sr      = 44100   ; frecuencia de muestra
kr      = 4410    ; controla la velocidad
ksmps   = 10      ; numero de frecuencia en un periodo
nchnls  = 1       ; numero de canales

       instr 001         ;Instrumento 001 esta iniciando
a1        oscil  10000, 440, 1   
          out    a1
      endin              ;Fin de instrumento
;Este es un comentario. Inicia con ';'.