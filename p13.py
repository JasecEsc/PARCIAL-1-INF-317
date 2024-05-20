import multiprocessing as mp
import math

def fibonacci(inicio, fin):
    # Función para generar la secuencia de Fibonacci en el rango [inicio, fin).
    secuencia = []
    for i in range(inicio, fin):
        p1 = ((1/math.sqrt(5)) * ((1 + math.sqrt(5))/2) ** i)
        p2 = ((1/math.sqrt(5)) * ((1 - math.sqrt(5))/2) ** i)
        pt = round(p1 - p2)
        secuencia.append(pt)
    return secuencia

if __name__ == "__main__":
    # Número total de términos deseados en la secuencia de Fibonacci
    cantidad_terminos = 1000

    # Número de procesadores disponibles
    cantidad_procesadores = mp.cpu_count()

    # Cálculo de la cantidad de términos que cada procesador generará
    terminos_por_procesador = cantidad_terminos // cantidad_procesadores

    # Calcular los límites de los rangos para cada procesador
    parametros = [(i * terminos_por_procesador, (i + 1) * terminos_por_procesador) for i in range(cantidad_procesadores)]

    # Agregar el resto de los términos al último procesador si hay división no exacta
    parametros[-1] = (parametros[-1][0], cantidad_terminos)

    # Iniciar el pool de procesos
    pool = mp.Pool()

    # Calcular Fibonacci para cada rango de términos
    resultados = pool.starmap(fibonacci, parametros)

    # Impresión de los resultados
    for i, resultado in enumerate(resultados):
        print(f"Procesador {i + 1}: {resultado}")
