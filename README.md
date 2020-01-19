# Arduino-micro-autonomo
Prototipo de Arduino Micro con pantalla, bateria y 6 pines I/O

Arduino micro autónomo
	por Jose Manuel Escuder

Se dice que Arduino es la navaja suiza de la electrónica digital y este proyecto pretende ser una navaja suiza basada en Arduino para medición de parámetros en cualquier tipo de ambiente, un sistema totalmente autónomo, portable, pequeño, alimentado por batería recargable y con pantalla integrada para mostrar datos.

La idea que persigo con este proyecto es tener una especie de consola portátil que me permita leer sensores ubicados en distintas localizaciones, de modo que sólo sea llegar al sitio en cuestión, conectar el sensor a uno de los pines de entrada y poder leer directamente en la pantalla los parámetros medidos por el sensor. Por ejemplo uno de los usos que le voy a dar es para controlar la temperatura y humedad dentro de un compostador, dentro del recipiente para elaborar el compost habrá fijo un sensor  DHT22 (que mide temperatura y humedad) y para conocer esos parámetros tan solo tendré que conectar el cable del sensor a la consola y podré verlos directamente en la pantalla.

Otro de los usos, futuros por que en esta primera versión no está implementado de momento, será como puerta de entrada al IoT (Internet of thigs o Internet de las cosas) al acoplarle un módulo WiFi ESP8266, mediante el cual se podrán enviar estas lecturas a servidores en la nube que recopilen datos, como por ejemplo The Things Network.

El corazón del proyecto es un Arduino micro, versión más pequeña del archiconocido Arduino UNO, soldado directamente a una pantalla LCD de 84x48 píxeles. Esta pantalla es la que llevaba montada el Nokia 5110 y se trata de una pantalla gráfica muy versatil y sencilla de utilizar gracias a las librerías desarrolladas por Adafruit.

Insertar imagen “frontal.jpg”

Para que el proyecto sea autónomo debe estar alimentado por una batería y para ello elegí una Lipo de 3’7v con una pequeña pcb que sirve a la vez para cargarla por medio de un conector micro-usb, tanto como step-up que proporciona a todo el sistema 5v para su funcionamiento. El circuito de alimentación se puede conectar y desconectar mediante un switch de dos posiciones.

Insertar imagen “bateria.jpg”

6 pines de entrada han sido habilitados para el  montaje, 3 de ellos son digitales correspondiendo a los pines 10, 11 y 12 del Arduino Micro. Los otros 3 son pines con capacidad analógica y son los marcados como A1, A2 y A3. Su disposición es tal que si miramos el prototipo de frente están colocados de izquierda a derecha en el siguiente orden A3, A2, A1, 12, 11 y 10, no parece un orden muy lógico, más bien parece un orden invertido y así es, es lo que pasa cuando uno cablea y suelda sin pensar que el acceso a los pines se hará por el otro lado.

Insertar imagen “pines.jpg” 

Los pines de entrada al sistema están montados sobre un pequeño pcb, de los de pistas continuas, con la pista central conectada al positivo de la alimentación, los terminales del fondo a GND y los terminales de la parte delantera a las entradas digitales y analógicas. Con esta disposición se pueden utilizar cables de servo de 3 hilos para conectar los sensores, lo cual es una ventaja importante ya que son unos cables muy fáciles de encontrar además de estar disponibles en multitud de longitudes diferentes, lo que hará que siempre podamos encontrar el adecuado para nuestras necesidades.

Conectado al pin digital 13 se encuentra conectado un pulsador, este servirá para navegar por las distintas pantallas del firmware del dispositivo e ir viendo las lecturas de las diferentes entradas. Este pulsador se encuentra conectado tal cual, es decir, sin resistencia que lo conecte a GND, la razón es sencilla, para ahorrar complejidad en el cableado de la parte posterior y también por no ser realmente necesario ya que mediante software se puede activar una resistencia interna que el micro lleva asociada a cada uno de los pines. Para activarla es necesario que en la declaración de los pines como entradas esta se defina como INPUT_PULLUP, al estar la resistencia conectada en disposición de pull-up vamos a tener que cuando el pulsador no esté accionado lo que leeremos desde el micro será un nivel lógico alto y, por el contrario, cuando se presione el pulsador la lectura cambiará a nivel bajo. Esto también parece ir en contra del sentido común pero al ser leído por el firmware realmente es indiferente siempre que le demos el tratamiento adecuado.

Insertar imagen “pantalla_activa.jpg”

Llegamos a la parte en la que hablaré un poco del código de ejemplo, que por ser algo largo no voy a incluir en este artículo, pero que está disponible en GitHub. Como todo código para Arduino comienza con llamadas a las librerías, en este caso las librerías para manejar la pantalla y una librería para leer un sensor de temperatura y humedad DHT22 que he utilizado para las pruebas y como ejemplo de como redactar una función de lectura de una de las entradas.
El código en sí es sencillo aunque extenso, cuenta con una función que detecta cambios de estado en el pulsador que comenté anteriormente, cada vez que se detecta un cambio en el estado del pulsador se aumenta el valor de una variable llamada level, en la sentencia switch-case cada valor de level dispara una función para cambiar de pantalla, cada una de las pantallas está relacionada con una función que será la encargada de leer un sensor y mostrar datos en la pantalla, activar algún tipo de actuador o simplemente mostrar información por la pantalla.

En un proyecto como este se aprende haciendo y también se descubren fallos de diseño del montaje. Como ya mencioné casi al principio falta añadir un módulo ESP8266 para añadir conectividad inalámbrica, también he detectado en las primeras pruebas que un sólo botón para cambiar de  pantalla limita mucho el tipo de acciones que se pueden realizar, por lo que un botón de 5 posiciones sería más adecuado. También he estado investigando la posibilidad de añadir un pequeño circuito analógico que me permita medir el nivel de la batería. Todo se andará, por que soy uno de esos makers que nunca dan un proyecto por terminado, pero de momento y para mostrar la idea y sus posibilidades creo que con esto basta.

