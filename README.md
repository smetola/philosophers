# philosophers

**philosophers** es un proyecto de simulación que pone a prueba los fundamentos de la programación concurrente, enfocándose en multithreading, multiprocessing y sincronización mediante mutexes.

<p align="center">
  <img src="[https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/f/55786af8-3f9c-484f-82b6-c40db345ef37/d1nw7fu-3fe328ae-5ef4-4686-bcba-6a3ee4765aa4.jpg?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJ1cm46YXBwOjdlMGQxODg5ODIyNjQzNzNhNWYwZDQxNWVhMGQyNmUwIiwic3ViIjoidXJuOmFwcDo3ZTBkMTg4OTgyMjY0MzczYTVmMGQ0MTVlYTBkMjZlMCIsImF1ZCI6WyJ1cm46c2VydmljZTpmaWxlLmRvd25sb2FkIl0sIm9iaiI6W1t7InBhdGgiOiIvZi81NTc4NmFmOC0zZjljLTQ4NGYtODJiNi1jNDBkYjM0NWVmMzcvZDFudzdmdS0zZmUzMjhhZS01ZWY0LTQ2ODYtYmNiYS02YTNlZTQ3NjVhYTQuanBnIn1dXX0.gwE9qeiB3P_4xRIdc44feNWgnI6Ma9yWfIBaY79lGvc](https://files.oaiusercontent.com/file-M15qm9QfbWooK7syZzkHER?se=2025-03-03T10%3A53%3A18Z&sp=r&sv=2024-08-04&sr=b&rscc=max-age%3D604800%2C%20immutable%2C%20private&rscd=attachment%3B%20filename%3D0dccbff9-60d3-4206-be3e-d36e7fedad52.webp&sig=HKT7Jgfuv6LC/0MBN9NgknohxDyrx42GfDe19Z8jNkk%3D)" alt="Fractal de Mandelbrot" width="75%">
</p>
![image](https://github.com/user-attachments/assets/b460d07c-adbb-4d55-838f-c52495c95dcd)

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
