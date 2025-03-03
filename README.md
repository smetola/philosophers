# philosophers

<h1 align="center">
  🚀 ¡Proyecto completado! 🚀
</h1>

<p align="center">
  Este proyecto está finalizado, pero pronto lo actualizaré en GitHub cuando esté en el campus.
</p>

**philosophers** es un proyecto de simulación que pone a prueba los fundamentos de la programación concurrente, enfocándose en multithreading, multiprocessing y sincronización mediante mutexes.

<p align="center">
  <img src="https://github.com/user-attachments/assets/b460d07c-adbb-4d55-838f-c52495c95dcd" alt="The dinning philosophers" width="30%">
</p>

## ¿De qué se trata?

En este proyecto, varios filósofos se sientan en una mesa redonda, cada uno con un tenedor a su izquierda y a su derecha. Los filósofos alternan entre **comer**, **pensar** y **dormir**. Para comer, deben tomar ambos tenedores, y si no logran hacerlo a tiempo, podrían "morir". La simulación se detiene cuando ocurre una de las siguientes situaciones:

- Un filósofo muere por inanición.
- Todos los filósofos han comido un número mínimo de veces (si se especifica).

## Características principales

- **Multithreading**: Cada filósofo es representado por un hilo, permitiendo la ejecución concurrente.
- **Mutexes**: Se utilizan para proteger los tenedores y evitar condiciones de carrera.
- **Gestión del tiempo**: Cada acción (comer, dormir, pensar) se ejecuta bajo restricciones temporales que simulan la realidad.
- **Logs precisos**: Se registra cada acción de los filósofos con marcas de tiempo en milisegundos.

## ¿Qué he aprendido?

- **Programación concurrente**: Profundización en la creación y gestión de hilos.
- **Sincronización**: Uso de mutexes para asegurar el acceso seguro a recursos compartidos y evitar data races.
- **Control de tiempos y estados**: Manejo de temporizadores para gestionar las acciones de cada filósofo.
- **Resolución de problemas algorítmicos**: Implementación de estrategias para prevenir deadlocks y garantizar que todos los filósofos tengan oportunidad de comer.
