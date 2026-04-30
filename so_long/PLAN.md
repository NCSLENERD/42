# so_long — Plan de travail

## Etat actuel

| Phase | Status |
|---|---|
| **Phase 0** — code stable (free, error_exit, retours coherents) | ✅ Fait |
| **Phase 1** — split en 6 fichiers, Makefile, .gitignore | ✅ Fait |
| **Phase 2** — afficher la map en MLX | 🔜 Prochaine etape |
| **Phase 3** — deplacement du joueur + collecte | a venir |
| **Phase 4** — compteur, victoire, polish | a venir |
| **Norminette** | a faire en fin de projet |

## Architecture actuelle des fichiers

```
so_long/
├── so_long.h          struct + prototypes
├── so_long.c          main + init_game + close_win
├── parse_map.c        verif_files, map_height, init_map
├── verif_struct.c     verif_lborne, verif_borne, verif_width
├── verif_content.c    verif_lcontent, verif_ec, verif_p, verif_content, verif_map
├── flood_fill.c       getln, dupmap, fill, is_solvable, flood_fill
├── utils.c            ft_strlenV2, free_tab, free_game, error_exit
├── get_nextline/      get_next_line + utils
├── minilibx-linux/    bibliotheque MLX
├── Makefile
└── .gitignore
```

---

# PHASE 2 — Afficher la map

## Vue d'ensemble

Aujourd'hui : la fenetre MLX s'ouvre vide.
Objectif : la fenetre affiche la map case par case avec les bonnes textures.

## Etape 1 — Trouver les textures XPM

5 textures necessaires, **toutes a la meme taille** (64x64 conseille) :

| Caractere map | Fichier XPM | Description |
|---|---|---|
| `'1'` | `wall.xpm` | Mur |
| `'0'` | `floor.xpm` | Sol |
| `'P'` | `player.xpm` | Joueur |
| `'C'` | `collect.xpm` | Objet a collecter |
| `'E'` | `exit.xpm` | Sortie |

**Ou les trouver :**
- GitHub : `so_long xpm` ou `42 so_long textures`
- OpenGameArt.org (sprites libres) — convertir avec `convert image.png image.xpm`
- itch.io (free assets section)

**Organisation :**
```
so_long/
└── textures/
    ├── wall.xpm
    ├── floor.xpm
    ├── player.xpm
    ├── collect.xpm
    └── exit.xpm
```

## Etape 2 — Etendre la struct dans `so_long.h`

Ajouter dans `t_game` :

```c
typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    int     collect_remain;
    int     nbmoves;
    void    *img_wall;       /* NOUVEAU */
    void    *img_floor;      /* NOUVEAU */
    void    *img_player;     /* NOUVEAU */
    void    *img_collect;    /* NOUVEAU */
    void    *img_exit;       /* NOUVEAU */
}   t_game;
```

Ajouter le define `TILE_SIZE` apres les includes :

```c
# define TILE_SIZE 64
```

Mettre a jour `init_game` dans `so_long.c` :

```c
void  init_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->map = NULL;
    game->map_width = 0;
    game->map_height = 0;
    game->player_x = 0;
    game->player_y = 0;
    game->collect_remain = 0;
    game->nbmoves = 0;
    game->img_wall = NULL;
    game->img_floor = NULL;
    game->img_player = NULL;
    game->img_collect = NULL;
    game->img_exit = NULL;
}
```

Ajouter les prototypes dans `so_long.h` :

```c
void  load_textures(t_game *game);
void  render_tile(t_game *game, int x, int y);
void  render_map(t_game *game);
```

## Etape 3 — Creer `render.c`

```c
/* render.c */
#include "so_long.h"
#include "minilibx-linux/mlx.h"

void  load_textures(t_game *game)
{
    int  w;
    int  h;

    game->img_wall = mlx_xpm_file_to_image(game->mlx,
                        "textures/wall.xpm", &w, &h);
    if (!game->img_wall)
        error_exit(game, "Cannot load wall texture");
    game->img_floor = mlx_xpm_file_to_image(game->mlx,
                        "textures/floor.xpm", &w, &h);
    if (!game->img_floor)
        error_exit(game, "Cannot load floor texture");
    game->img_player = mlx_xpm_file_to_image(game->mlx,
                        "textures/player.xpm", &w, &h);
    if (!game->img_player)
        error_exit(game, "Cannot load player texture");
    game->img_collect = mlx_xpm_file_to_image(game->mlx,
                        "textures/collect.xpm", &w, &h);
    if (!game->img_collect)
        error_exit(game, "Cannot load collect texture");
    game->img_exit = mlx_xpm_file_to_image(game->mlx,
                        "textures/exit.xpm", &w, &h);
    if (!game->img_exit)
        error_exit(game, "Cannot load exit texture");
}

void  render_tile(t_game *game, int x, int y)
{
    void  *img;
    char  c;

    c = game->map[y][x];
    if (c == '1')
        img = game->img_wall;
    else if (c == 'C')
        img = game->img_collect;
    else if (c == 'E')
        img = game->img_exit;
    else if (c == 'P')
        img = game->img_player;
    else
        img = game->img_floor;
    mlx_put_image_to_window(game->mlx, game->win, img,
                             x * TILE_SIZE, y * TILE_SIZE);
}

void  render_map(t_game *game)
{
    int  x;
    int  y;

    y = 0;
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
        {
            render_tile(game, x, y);
            x++;
        }
        y++;
    }
}
```

**Note** : `load_textures` fait 5 fois le meme pattern. Si tu veux passer la norminette (5 fonctions max par fichier), c'est OK ici car render.c contient seulement 3 fonctions. Tu peux factoriser plus tard si besoin.

## Etape 4 — Mettre a jour le Makefile

Ajouter `render.c` dans `SRC` :

```make
SRC = flood_fill.c parse_map.c utils.c verif_content.c verif_struct.c \
      so_long.c render.c \
      get_nextline/get_next_line_utils.c get_nextline/get_next_line.c
```

## Etape 5 — Brancher dans le main

Dans `so_long.c::main`, **apres** la validation et **avant** `mlx_loop` :

```c
init_map(&game, argv[1]);
if (!verif_map(&game))
    error_exit(&game, "Invalid map");

/* PHASE 2 — init MLX + textures + render */
game.mlx = mlx_init();
game.win = mlx_new_window(game.mlx,
                            game.map_width * TILE_SIZE,
                            game.map_height * TILE_SIZE,
                            "so_long");
mlx_hook(game.win, 17, 0, close_win, game.mlx);
load_textures(&game);                            /* nouveau */
render_map(&game);                                /* nouveau */

mlx_loop(game.mlx);
free_game(&game);
return (0);
```

**Note importante** : la fenetre s'adapte maintenant a la map. Plus de `800, 600` en dur.

## Etape 6 — Etendre `free_game` dans `utils.c`

Quand on charge des images, il faut les detruire avant de quitter :

```c
void  free_game(t_game *game)
{
    if (game->map)
    {
        free_tab(game->map, game->map_height);
        game->map = NULL;
    }
    if (game->img_wall)
        mlx_destroy_image(game->mlx, game->img_wall);
    if (game->img_floor)
        mlx_destroy_image(game->mlx, game->img_floor);
    if (game->img_player)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->img_collect)
        mlx_destroy_image(game->mlx, game->img_collect);
    if (game->img_exit)
        mlx_destroy_image(game->mlx, game->img_exit);
}
```

**A ajouter en haut de `utils.c`** :
```c
#include "minilibx-linux/mlx.h"
```

(pour avoir `mlx_destroy_image`)

## Etape 7 — Tester

```bash
make
./so_long test.ber
```

Tu dois voir une fenetre dimensionnee a la map, avec les bonnes textures a chaque case.

---

## Pieges courants — checklist debug

- ❌ **Fenetre noire / textures invisibles**
  → Verifie le chemin des XPM (`textures/wall.xpm` doit etre **relatif au dossier d'execution**, pas a celui du source)

- ❌ **Segfault au demarrage**
  → `mlx_xpm_file_to_image` a retourne NULL (fichier introuvable ou XPM mal forme)
  → Le `if (!game->img_X)` doit declencher `error_exit`, jamais ignorer

- ❌ **Map decalee / cases qui se chevauchent**
  → Toutes tes textures n'ont pas la meme taille
  → Verifier que toutes sont 64x64 (ou TILE_SIZE)

- ❌ **Compile error : `undefined reference to mlx_xpm_file_to_image`**
  → Tu as oublie `#include "minilibx-linux/mlx.h"` dans render.c
  → Ou MLX n'est pas linke (verifier `MLX_FLAGS` dans Makefile)

- ❌ **`mlx_put_image_to_window` ne dessine rien**
  → La window n'est pas encore creee, ou tu as inverse `x` et `y`
  → Rappel : `x` horizontal (colonne = `map_width`), `y` vertical (ligne = `map_height`)

---

## Apres Phase 2 — apercu Phase 3

Quand l'affichage marche, etape suivante :
- Creer `events.c` avec `key_press(int keycode, t_game *game)`
- Hook clavier : `mlx_hook(win, 2, 1L<<0, key_press, &game)`
- Fonction `try_move(t_game *game, int new_x, int new_y)` qui :
  - Verifie que la case n'est pas un mur
  - Si `'C'` : `collect_remain--`, remplace par `'0'`
  - Si `'E'` et `collect_remain == 0` : victoire
  - Met a jour `player_x`, `player_y`, et la map
  - Re-render

---

## Reference rapide — fonctions MLX utiles

```c
/* Init / cleanup */
void  *mlx_init(void);
void  *mlx_new_window(void *mlx, int w, int h, char *title);
int   mlx_destroy_window(void *mlx, void *win);
int   mlx_destroy_display(void *mlx);

/* Images */
void  *mlx_xpm_file_to_image(void *mlx, char *file, int *w, int *h);
int   mlx_put_image_to_window(void *mlx, void *win, void *img, int x, int y);
int   mlx_destroy_image(void *mlx, void *img);

/* Events */
int   mlx_hook(void *win, int event, int mask, int (*f)(), void *param);
int   mlx_loop(void *mlx);
int   mlx_loop_end(void *mlx);

/* Hook event codes (sur Linux) :
   2  = KeyPress
   3  = KeyRelease
   17 = DestroyNotify (clic sur la croix)
*/
```

---

## TL;DR — etapes a faire dans l'ordre

1. ⬜ Trouver 5 XPM (64x64) → dossier `textures/`
2. ⬜ Ajouter 5 champs `void *img_*` dans `t_game`
3. ⬜ Ajouter `# define TILE_SIZE 64` dans `so_long.h`
4. ⬜ Mettre a jour `init_game` (NULL pour les 5 images)
5. ⬜ Creer `render.c` avec `load_textures`, `render_tile`, `render_map`
6. ⬜ Ajouter `render.c` au Makefile
7. ⬜ Brancher `load_textures` + `render_map` dans le main (avant `mlx_loop`)
8. ⬜ Ajuster `mlx_new_window` aux dimensions de la map
9. ⬜ Etendre `free_game` pour detruire les images
10. ⬜ Tester avec `make && ./so_long test.ber`
