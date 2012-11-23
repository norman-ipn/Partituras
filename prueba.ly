%Para compilar:$ lilypond prueba.ly
% Y genera un pdf y vs creando la partitura ;)
% Cada nota tiene asignado una letra en espcifico como se muestra acontinuación
% do, re, mi, fa, sol, la, si (según el sistema latino de notación).
& c,  d,  e,   f,  g,   a,  b (según el sistema inglés de notación musical, también llamado denominación literal).

\version "2.12.3"
{
 e' a' c'  % Por lo tanto creamos una pequeña melodia con mi - la - do
}

% NOTA IMPORTANTE: el ' indica un tiempo de silencio entre cada nota si no lleva ' indicaremos
% en SONIDO que las notas son seguidas, vease el manual de LilyPond.

