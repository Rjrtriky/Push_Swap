*Este proyecto ha sido creado como parte del currículo de 42 por rjuarez-*

# libft

## 📖 Descripción

DEFINICION:

Libft es una implementación personalizada de funciones de la biblioteca estándar de C, creada como parte del currículo de 42. Este proyecto incluye versiones propias de funciones comunes de string.h, ctype.h, stdlib.h, y más, además de funciones adicionales útiles para la manipulación de cadenas y memoria.

FUNCIONES IMPLEMENTADAS:
	Funciones de Caracteres (ctype.h)
	
	-ft_isalpha: Verifica si un carácter es alfabético
		int ft_isalpha(int nbr);
			Parámetros de entrada:
				c: El carácter a evaluar (pasado como int para compatibilidad)
			Resultado:
				Correcto: 1 si el carácter es una letra (A-Z o a-z)
				Error: 0 si el carácter no es una letra
	-ft_isdigit: Verifica si un carácter es un dígito decimal
		int ft_isdigit(int nbr);
			Parámetros de entrada:
				c: El carácter a evaluar (pasado como int para compatibilidad)
			Resultado:
				Correcto: 1 si el carácter es un dígito (0-9)
				Error: 0 si el carácter no es un dígito
	-ft_isalnum: Verifica si el carácter es alfanumérico (letra o dígito)
		int ft_isalnum(int nbr);
			Parámetros de entrada:
				c: El carácter a evaluar (pasado como int para compatibilidad)
			Resultado:
				Correcto: 1 si el carácter es una letra (A-Z o a-z) o un dígito (0-9)
				Error: 0 si el carácter no es alfanumérico
	-ft_isascii: Verifica si el valor corresponde a un carácter ASCII válido
		int ft_isascii(int nbr);
			Parámetros de entrada:
				c: El valor a evaluar (pasado como int para compatibilidad)
			Resultado:
				Correcto: 1 si el valor está en el rango ASCII (0-127)
				Error: 0 si el valor está fuera del rango ASCII
	-ft_isprint: Verifica si el carácter es imprimible (incluyendo espacio)
		int ft_isprint(int nbr);
			Parámetros de entrada:
				c: El carácter a evaluar (pasado como int para compatibilidad)
			Resultado:
				Correcto: 1 si el carácter es imprimible (32-126 en ASCII)
				Error: 0 si el carácter no es imprimible (0-31 y 127 en ASCII)
	-ft_toupper: Convierte un carácter minúscula a mayúscula
		int ft_toupper(int c);
			Parámetros de entrada:
				c: El carácter a convertir (pasado como int para compatibilidad)
			Resultado:
				Correcto: Carácter en mayúscula si era minúscula
				Error: El mismo carácter sin cambios si no era minúscula
	-ft_tolower: Convierte un carácter mayúscula a minúscula
		int ft_tolower(int c);
			Parámetros de entrada:
				c: El carácter a convertir (pasado como int para compatibilidad)
			Resultado:
				Correcto: Carácter en minúscula si era mayúscula
				Error: El mismo carácter sin cambios si no era mayúscula
Funciones de Cadenas (string.h)

	-ft_strlen: Calcula la longitud de una cadena de caracteres
			size_t ft_strlen(const char *str);
			Parámetros de entrada:
				s: La cadena de la cual calcular la longitud
			Resultado:
				Correcto: Número de caracteres antes del nulo terminador
				Error: Comportamiento indefinido si la cadena es nula
	-ft_strchr: Busca la primera aparición de un carácter en una cadena
		char *ft_strchr(const char *s, int c);
			Parámetros de entrada:
				s: La cadena donde se realiza la búsqueda
				c: El carácter a buscar (pasado como int, convertido a char)
			Resultado:
				Correcto: Puntero a la primera aparición del carácter
				Error: NULL si el carácter no se encuentra en la cadena
	-ft_strrchr: Busca la última aparición de un carácter en una cadena
		char *ft_strrchr(const char *s, int c);
			Parámetros de entrada:
				s: La cadena donde se realiza la búsqueda
				c: El carácter a buscar (pasado como int, convertido a char)
			Resultado:
				Correcto: Puntero a la última aparición del carácter
				Error: NULL si el carácter no se encuentra en la cadena
	-ft_strncmp: Compara dos cadenas hasta un número máximo de caracteres
		int ft_strncmp(const char *s1, const char *s2, size_t size);
			Parámetros de entrada:
				s1: Primera cadena a comparar
				s2: Segunda cadena a comparar
				n: Número máximo de caracteres a comparar
			Resultado:
				Iguales: 0 si las cadenas son iguales en los primeros n caracteres
				Diferencia: Entero distinto de cero indicando la diferencia (positivo si s1 > s2, negativo si s1 < s2)
	-ft_strlcpy: Copia una cadena a un buffer con límite de tamaño, garantizando terminación nula
		size_t ft_strlcpy(char *dest, const char *src, size_t size);
			Parámetros de entrada:
				dest: Buffer destino donde se copiará la cadena
				src: Cadena origen a copiar
				size: Tamaño del buffer destino
			Resultado:
				Longitud de la cadena origen (sin incluir el nulo terminador)
	-ft_strlcat: Concatena dos cadenas de forma segura, limitando el tamaño total
		size_t ft_strlcat(char *dest, const char *src, size_t size);
			Parámetros de entrada:
				dst: Puntero al buffer destino
				src: Puntero al string fuente a concatenar
				size: Tamaño total del buffer destino
			Resultado:
				Longitud total que tendría la cadena resultante (sin el null final)
	-ft_strnstr: Busca la primera aparición de una subcadena en una cadena, con límite de longitud
		char *ft_strnstr(const char *big, const char *little, size_t len);

		Parámetros de entrada:
			haystack: Cadena principal donde buscar
			needle: Subcadena a buscar
			len: Número máximo de caracteres a examinar en haystack
		Resultado:
			Correcto: Puntero a la primera aparición de needle en haystack
			Error: NULL si needle no se encuentra dentro de los primeros len caracteres
	-ft_strdup: Crea en memoria un clon de una variable string
		char *ft_strdup(const char *ori);
			Parámetros de entrada:
				ori: Puntero al string original a duplicar
			Resultado:
				Correcto: Puntero con la nueva dirección de memoria donde está el duplicado de la cadena
				Error: NULL
	-ft_substr: Reserva memoria y devuelve una substring de la string 's'
		char *ft_substr(char const *s, unsigned int start, size_t len);
			Parámetros de entrada:
				s: La string de la que crear la substring
				start: El índice del carácter en 's' desde el que empezar la substring
				len: La longitud máxima de la substring
			Resultado:
				Correcto: Substring creada con malloc
				Error: NULL si falla la reserva de memoria
	-ft_strjoin: Genera un puntero a una nueva cadena que es la unión de las 2 que se pasan como parámetros
		char *ft_strjoin(char const *s1, char const *s2);
			Parámetros de entrada:
				s1: Puntero a la primera cadena
				s2: Puntero a la segunda cadena
			Resultado:
				Correcto: Puntero a la nueva cadena
				Error: NULL si falla al reservar memoria
	-ft_strtrim: Elimina los caracteres especificados en 'set' al principio y al final de la cadena s1
		char *ft_strtrim(char const *s1, char const *set);
			Parámetros de entrada:
				s1: La string que debe ser recortada
				set: Los caracteres a eliminar de la string
			Resultado:
				Correcto: Cadena recortada
				Error: NULL si falla al reservar memoria
	-ft_split: Divide una cadena en subcadenas usando un carácter delimitador
		char **ft_split(char const *s, char c);
			Parámetros de entrada:
				s: Cadena a separar
				c: Caracter delimitador
			Resultado:
				Correcto: El array de nuevas strings resultante de la separación
				Error: NULL si falla al reservar memoria
	-ft_strmapi: Aplica una función a cada carácter de una cadena creando una nueva cadena con los resultados
		char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
			Parámetros de entrada:
				s: La string que iterar
				f: La función a aplicar sobre cada carácter
			Resultado:
				Correcto: La string creada tras el correcto uso de 'f' sobre cada carácter
				Error: NULL si falla la reserva de memoria
	-ft_striteri: Aplica una función a cada carácter de una cadena, pasando su índice
		void ft_striteri(char *s, void (*f)(unsigned int, char*));
			Parámetros de entrada:
				s: La string que iterar
				f: La función a aplicar sobre cada carácter
			Resultado: Nada
Funciones de Memoria (string.h)

	-ft_memset: Rellena un bloque de memoria con un valor específico
		void *ft_memset(void *ptr, int value, size_t len);
			Parámetros de entrada:
				s: Puntero al bloque de memoria a rellenar
				c: Valor a establecer (pasado como int, convertido a unsigned char)
				n: Número de bytes a establecer
			Resultado:
				Correcto: Puntero al bloque de memoria original
	-ft_bzero: Escribe ceros en una zona de memoria de tamaño especificado
		void *ft_bzero(void *ptr, size_t len);
			Parámetros de entrada:
				s: Puntero al bloque de memoria a inicializar
				n: Número de bytes a establecer a cero
			Resultado: No retorna valor (función void)
	-ft_memcpy: Copia n bytes desde un área de memoria origen a un área de memoria destino
		void *ft_memcpy(void *dest, const void *org, size_t len);
			Parámetros de entrada:
				dest: Puntero al bloque de memoria destino
				src: Puntero al bloque de memoria origen
				n: Número de bytes a copiar
			Resultado:
				Correcto: Puntero al bloque de memoria destino
				Error: Comportamiento indefinido si los bloques se solapan
	-ft_memmove: Copia n bytes de un área de memoria a otra, manejando solapamientos
		void *ft_memmove(void *dest, const void *org, size_t len);
			Parámetros de entrada:
				dest: Puntero al bloque de memoria destino
				src: Puntero al bloque de memoria origen
				n: Número de bytes a copiar
			Resultado:
				Correcto: Puntero al bloque de memoria destino
	-ft_memchr: Busca la primera aparición de un carácter en un bloque de memoria
		void *ft_memchr(const void *str, int c, size_t len);
			Parámetros de entrada:
				s: Puntero al bloque de memoria donde se realiza la búsqueda
				c: Carácter a buscar (pasado como int, convertido a unsigned char)
				n: Número de bytes a examinar
			Resultado:
				Correcto: Puntero a la primera aparición del carácter
				Error: NULL si el carácter no se encuentra en los primeros n bytes
	-ft_memcmp: Compara dos bloques de memoria byte a byte
		int ft_memcmp(const void *s1, const void *s2, size_t n);
			Parámetros de entrada:
				s1: Puntero al primer bloque de memoria
				s2: Puntero al segundo bloque de memoria
				n: Número de bytes a comparar
			Resultado:
				Correcto: 0 si los bloques son iguales en los primeros n bytes
				Diferencia: Entero distinto de cero indicando la diferencia (positivo si s1 > s2, negativo si s1 < s2)
	-ft_calloc: Reserva un espacio en memoria y pone todo el espacio a 0
		void *ft_calloc(size_t num, size_t size);
			Parámetros de entrada:
				num: número de variables
				size: tamaño de las variables
			Resultado:
				Correcto: puntero a la dirección de memoria reservada
				Error: NULL
Funciones de Conversión (stdlib.h)

	-ft_atoi: Convierte un string a número entero. Limita el número a los límites de int, tanto por arriba como por abajo
		int ft_atoi(const char *str);
			Parámetros de entrada:
				s: Un puntero a una cadena
			Resultado:
				Correcto: Un número entero
				Error: 0
	-ft_itoa: Genera una cadena que represente el valor entero recibido como argumento
		char *ft_itoa(int n);
			Parámetros de entrada:
				n: el entero a convertir
			Resultado:
				Correcto: La string que represente el número
				Error: NULL si falla la reserva de memoria
Funciones de Salida

	-ft_putchar_fd: Imprime un carácter usando write en el file descriptor especificado
		void ft_putchar_fd(char c, int fd);
			Parámetros de entrada:
				c: caracter a escribir
				fd: fichero donde se escribe (STDIN_FILENO=0, STDOUT_FILENO=1, STDERR_FILENO=2)
			Resultado: Nada
	-ft_putstr_fd: Envía una cadena al fichero especificado
		void ft_putstr_fd(char *s, int fd);
			Parámetros de entrada:
				s: cadena a escribir
				fd: fichero donde se escribe (STDIN_FILENO=0, STDOUT_FILENO=1, STDERR_FILENO=2)
			Resultado: Nada
	-ft_putendl_fd: Imprime una cadena seguida de un salto de línea en un fichero de salida
		void ft_putendl_fd(char *s, int fd);
			Parámetros de entrada:
				s: cadena a escribir
				fd: fichero donde se escribe (STDIN_FILENO=0, STDOUT_FILENO=1, STDERR_FILENO=2)
			Resultado: Nada
	-ft_putnbr_fd: Imprime un número entero en un fichero de salida que se indica
		void ft_putnbr_fd(int n, int fd);
			Parámetros de entrada:
				n: número entero a escribir
				fd: fichero donde se escribe (STDIN_FILENO=0, STDOUT_FILENO=1, STDERR_FILENO=2)
			Resultado: Nada
Funciones Bonus de Listas Enlazadas

	-ft_lstnew: Crea un nuevo nodo (malloc) con el contenido 'content' y el puntero al siguiente nodo a NULL
		t_list *ft_lstnew(void *content);
			Parámetros de entrada:
				content: el contenido con el que crear el nodo
			Resultado:
				Correcto: Devuelve el nuevo nodo
				Error: Devuelve NULL si falla la reserva de memoria
	-ft_lstadd_front: Añade el nodo 'new' al principio de la lista 'lst'
		void ft_lstadd_front(t_list **lst, t_list *new);
			Parámetros de entrada:
				lst: la dirección de un puntero al primer nodo de una lista
				new: un puntero al nodo que añadir al principio de la lista
			Resultado: Nada
	-ft_lstadd_back: Añade el nodo nuevo enviado por parámetro al final de la lista
		void ft_lstadd_back(t_list **lst, t_list *new);
			Parámetros de entrada:
				lst: el puntero al primer nodo de una lista
				new: el puntero a un nodo que añadir a la lista
			Resultado: Ninguno
	-ft_lstsize: Cuenta el número de nodos de una lista
		int ft_lstsize(t_list *lst);
			Parámetros de entrada:
				lst: el principio de la lista
			Resultado:
				Correcto: Número de nodos de la lista
	-ft_lstlast: Devuelve el último nodo de la lista
		t_list *ft_lstlast(t_list *lst);
			Parámetros de entrada:
				lst: puntero al primer nodo de la lista
			Resultado:
				Puntero al último nodo de la lista
	-ft_lstdelone: Toma como parámetro un nodo 'lst' y libera la memoria del contenido utilizando la función 'del', además de liberar el nodo
		void ft_lstdelone(t_list *lst, void (*del)(void*));
			Parámetros de entrada:
				lst: el nodo a liberar
				del: un puntero a la función utilizada para liberar el contenido del nodo
			Resultado: Nada
	-ft_lstclear: Elimina y libera el nodo 'lst' dado y todos los consecutivos de ese nodo, utilizando la función 'del' y free(3)
		void ft_lstclear(t_list **lst, void (*del)(void*));
			Parámetros de entrada:
				lst: la dirección de un puntero a un nodo
				del: un puntero a función utilizado para eliminar el contenido de un nodo
			Resultado: Nada
	-ft_lstiter: Itera la lista 'lst' y aplica la función 'f' en el contenido de cada nodo
		void ft_lstiter(t_list *lst, void (*f)(void *));
			Parámetros de entrada:
				lst: un puntero al primer nodo
				f: un puntero a la función que utilizará cada nodo
			Resultado: Nada
	-ft_lstmap: Itera la lista 'lst' y aplica la función 'f' al contenido de cada nodo. Crea una lista resultante
		t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
			Parámetros de entrada:
				lst: un puntero a un nodo
				f: la dirección de un puntero a una función usada en la iteración
				del: un puntero a función utilizado para eliminar el contenido de un nodo
			Resultado:
				Correcto: La nueva lista
				Error: NULL si falla la reserva de memoria

## ⚙️ Instrucciones

COMPILACION

	make
	make bonus

Opciones de  makefile

		make clean	# Elimina archivos objeto (.o)
		make fclean	# Elimina archivos objeto y la biblioteca
		make re		# Recompila todo desde cero
		make all	# Compila la biblioteca básica (por defecto)

INCLUIR EN PROYECTO

En la cabecera  de fichero se debe incluir:

	#include "libft.h"

DESCRIPCION DE LAS FUNCIONES:


## 📚 Recursos

REFERENCIAS CLASICAS:

	-Documentación de read() en Linux con man y en https://man7.org/linux/man-pages/man2/read.2.html
	-Tutoriales sobre manejo de memoria dinámica en C.
	-Ejemplos de proyectos previos de 42 relacionados con libft.
