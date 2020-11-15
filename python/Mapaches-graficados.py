from bokeh.plotting import figure, output_file, show
import random

def generar(cantidad):
    Mapaches = []
    for i in range(1, cantidad + 1):
        Mapaches.append(random.randint(1, 365))
    return Mapaches

def comprobar(Mapaches):
    coincidencias = 0
    for day in range (1, 366):
        suma_coincidencias = 0
        for i in range(0, len(Mapaches)):
            if Mapaches[i] == day:
                suma_coincidencias += 1
        if suma_coincidencias > 1:
            coincidencias += 1
    return coincidencias

if __name__ == "__main__":
    x_cantidad = []
    y_coincidencias = []
    graphic = figure()
    output_file("Gráfica.html")

    for index in range(0, 100):
        x_cantidad.append(index + 1)
        Mapaches = generar(index + 1)
        y_coincidencias.append(comprobar(Mapaches))

    print(x_cantidad, "\n")
    print(y_coincidencias)

    graphic.line(x_cantidad, y_coincidencias, line_width = 2)
    show(graphic)