from bokeh.plotting import figure, output_file, show
import random

x_mapaches = []
y_porcentaje = []

porcentaje = 1.0

for i in range(1, 101):
    porcentaje *= (366 - i) / 365
    x_mapaches.append(i)
    y_porcentaje.append((1 - porcentaje) * 100)
    print ('%3d mapaches: %10.6f %%' % (i, (1 - porcentaje) * 100))

graphic = figure()
output_file("Gráfica.html")
graphic.line(x_mapaches, y_porcentaje, line_width = 2)
show(graphic)