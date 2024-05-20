import multiprocessing as mp

# Función para calcular una porción de la aproximación de Pi
def calcular_aproximacion_pi(inicio, fin):
    suma = 0
    for i in range(inicio, fin):
        suma += (-1) ** i / (2 * i + 1)
    return suma

if __name__ == "__main__":
    num_subintervalos = 1000000 # Número total de subintervalos
    num_procesadores = mp.cpu_count() # Número de procesadores disponibles
    subintervalos_por_procesador = num_subintervalos // num_procesadores # Subintervalos por procesador

    # Crear un pool de procesos
    pool = mp.Pool()
    # Crear una lista de parámetros para cada proceso
    parametros = [(i * subintervalos_por_procesador, (i + 1) * subintervalos_por_procesador) for i in range(num_procesadores)]
    # Ejecutar la función calcular_aproximacion_pi en paralelo
    resultados = pool.starmap(calcular_aproximacion_pi, parametros)

    # Sumar los resultados de todos los procesos y multiplicar por 4 para obtener Pi
    pi = 4 * sum(resultados)
    print("Aproximación de Pi:", pi)
