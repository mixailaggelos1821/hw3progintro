Zoomba Readme


οδηγίες:

1. Κατεβάστε το zoomba.c από το "src".
2. ενεργοποίηση με:
   ```
   gcc -Ofast -Wall -Wextra -Werror -pedantic -o zoomba zoomba.c -lm
   ```
3. δινουμαι τα locations του zoomba, του target και του χαρτι σε τυπο: 

ROOM_DIMENSION_N
ZOOMBA_X ZOOMBA_Y ZOOMBA_TARGET_X ZOOMBA_TARGET_Y
ROOM_ENCODED_AS_1s_AND_0s

παραδειγμα:

10
1 1 8 8
0000000000
0110000000
0110000000
0110000000
0110000000
0110000000
0110000000
0110000000
0110000000
0000000000


### Περιγραφή Λειτουργίας
το προγραμμα zoomba ειναι φτιαγμένο για να αναλύει ενα δωμάτιο και να βρησκει τον καλυτερο δρόμο για να φτασει στο target,
το οποιο εχει σημειωθει απο το προγραμμα μαζι με τον χαρτι και την δική του τοποθεσία

