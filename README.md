# 3DGame_in_C
## Учебный проект.
## Целью проекта cub3dявляется создание 3D-игры с использованием метода raycasting, который представляет собой метод рендеринга, реализованный во всемирно известной Wolfenstein 3Dигре.

## Разбор карты
Исполняемый cub3Dфайл получает в качестве единственного аргумента прочитанный нами файл карты, который должен относиться к .cubтипу файла.

Пример карты:
```
R 1070 840
NO textures/redbrick.xpm
SO textures/green_tex.xpm
WE textures/new_xpm.xpm
EA textures/write_tex.xpm
S textures/barrel.xpm
K textures/pillar.xpm
F textures/floor.xpm
C textures/ceiling.xpm

11111111111111111111111111111
10000000001100000000000021111
10110000000003000002000000111
1001000000010000S000000001111
11111011000100011111000000001
10000300001100011111000000001
11110000000111000101100111011
11110000000111000101010010001
11000000110101001100000010001
10002000000000001100000000001
10000000003000000001010000301
11000001110101011111011110111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Рейкастинг
Raycasting — это метод рендеринга для создания 3D на 2D-карте. Логика RayCasting заключается в том, чтобы отбрасывать лучи в направлении взгляда игрока. По сути, нужно проверить расстояние между игроком и ближайшей стеной (то есть точкой, где луч падает на стену), чтобы вычислить высоту вертикальных линий, которые рисуются

