import multiprocessing as mp

def generar_serie(inicio, fin):
    # Función para generar una serie de números pares en el rango [inicio, fin).
    serie = []
    for i in range(inicio, fin):
        serie.append(2 * i)
    return serie

if __name__ == "__main__":
    # Número de términos deseados en la serie
    cantidad_terminos = 100

    # Número de procesadores disponibles
    cantidad_procesadores = mp.cpu_count()

    # Cálculo de la cantidad de términos que cada procesador generará
    terminos_por_procesador = cantidad_terminos // cantidad_procesadores

    # Creación del grupo de procesos
    pool = mp.Pool()

    # Definición de los rangos de términos para cada proceso
    parametros = [(i * terminos_por_procesador, (i + 1) * terminos_por_procesador) for i in range(cantidad_procesadores)]

    # Generación de la serie de números pares utilizando múltiples procesos
    resultados = pool.starmap(generar_serie, parametros)

    # Impresión de los resultados
    for i, resultado in enumerate(resultados):
        print(f"Procesador {i + 1}: {resultado}")
