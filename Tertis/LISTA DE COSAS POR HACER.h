/*
 Estimados,
 * 
 * dejemos aca las funciones que hay que hacer, que recibe, que devuelve y dentro de que funciones se incluye. 
 * NO ES LA LÓGICA DEL PROGRAMA sino simplemente para guiarnos qué va en donde y hacer comentarios sobre qué falta en cada función.
 * Si ponemos tipo de dato "???" es que no tenemos la más minima idea de que va a recibir o devolver, es decir, no está definida
 * la lógica, pero si reconocemos la necesidad de esa función.
 * 
 * void initTeturisu(PIECE * tetBoard){
 * 
 *      void initMat(PIECE * tetBoard) Recibe un puntero a la matriz del tablero de tetris y no devuelve nada, pues ya inicializa todo en su lógica.
 *      ??? initPiece(???) //No sé que recibe pero se supone que me genera la primer NEXT PIECE del juego para que después SPAWN simplemente tome esa pieza.
 * 
 * }
 * 
 * ??? nextPiece(???){ //Esta función spawnea la pieza actual y luego genera la siguiente que vendrá
 *      ??? TransfNextP(???) //Esta es la que toma la que ya está
 *      ??? SpawnNextP(???) //Esta es la que spawnea la siguiente
 * }
 * 
 * ??? Game(???){ //Esta es la función que en general se ocupa de toda la parte jugable
 *      ??? rotate(???); //Accede aca si se presiona el input que haga rotar la pieza
 *      ??? move(???); //Entra aca si se presiona el input que mueva la pieza
 *      ??? fall(???); //Aca debería entrar cada cierto tiempo para hacer que la pieza caiga. ¿Coldetect no debería estar aca adentro? Porque tiene que fijarse si va a chocar antes de bajarla
 *      ??? colDetect(???); //Mira si se va a chocar
 *      ??? fixPiece(???); //Fija la pieza si colisionó.
 * }
 * 
 * ??? pointDetect(???){
 *      ??? detectRows(???){
 *              ??? addRowsDel(???);
 *      }
 *      uint8_t addScore(uint8_t rowsComp); //Devuelve  puntaje en función de cuantas filas se rompieron (hay que ver como se agrega el puntaje).
 *      ??? deleteRows(???); //Elimina las filas completa y baja un bloque TODO LO QUE ESTÉ POR ENCIMA DE CADA FILA. Hay que tener cuidado porque si se eliminan dos filas separadas, algunas bajan una y otra dos y otras 3. 
 *}
 * 
 * ??? kiruTeturisu(???){} //Esta muestra la pantalla de Game Over según la plataforma. Permite hacer Quit, Restart. Muestra el SCORE y puede mostrar si se alcanzó un nuevo record.
 * 
 */