import gi
import math
import tictactoe

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk

class Gui(Gtk.Window):
    
    def __init__(self):
        super().__init__(title="Tictactoe")
        self.set_size_request (400, 400)

        # main vertical box : drawing area + hbox (label, button1, button2)
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        self.add(vbox)

        # drawing area
        self.drawingarea = Gtk.DrawingArea()
        self.drawingarea.add_events(Gdk.EventMask.BUTTON_PRESS_MASK)
        self.drawingarea.connect("draw", self.on_draw)
        self.drawingarea.connect("button-press-event", self.on_area_button_press)
        vbox.pack_start(self.drawingarea, True, True, 0)

        # horizontal box
        hbox = Gtk.Box()
        vbox.pack_end(hbox, False, False, 0)
        # label
        self.label = Gtk.Label(label="RougeJoue")
        hbox.pack_start(self.label, True, True, 0)
        # button1
        button1 = Gtk.Button(label="rejouer")
        button1.connect("clicked", self.on_button1_clicked)
        hbox.pack_start(button1, True, True, 0)
        # button2
        button2 = Gtk.Button(label="quitter")
        button2.connect("clicked", self.on_button2_clicked)
        hbox.pack_start(button2, True, True, 0)

        # TODO create game (from the C++ module)
        self.jeu = tictactoe.Jeu()

    def on_draw(self, widget, context):

        # TODO on_draw
        
        width = widget.get_allocated_width()
        height = widget.get_allocated_height()

        context.set_source_rgb(0, 0, 0)
        context.rectangle(0, 0, width, height)
        context.fill()

        context.set_source_rgb(0.5, 0.5, 0.5)
        context.set_line_width(3)
        context.move_to(width/3, 0)
        context.line_to(width/3, height)

        context.move_to((width/3)*2, 0)
        context.line_to((width/3)*2, height)

        context.move_to(0, (height/3))
        context.line_to(width, (height/3))

        context.move_to(0, (height/3)*2)
        context.line_to(width, (height/3)*2)

        context.stroke()


    def on_area_button_press(self, widget, event):
        if event.button == 1:
            match self.jeu.getStatus():
                case tictactoe.Status.RougeJoue:
                    self.label.set_text("RougeJoue")
                case tictactoe.Status.RougeGagne:
                    self.label.set_text("RougeGagne")
                case tictactoe.Status.VertJoue:
                    self.label.set_text("VertJoue")
                case tictactoe.Status.VertGagne:
                    self.label.set_text("VertGagne")
                case tictactoe.Status.Egalite:
                    self.label.set_text("Egalite")
            print('changement etat')
            

    def on_button1_clicked(self, widget):
        # TODO on_button1_clicked
        self.jeu.raz()
        print('Jeu réinitialisé')
        self.drawingarea.queue_draw()

    def on_button2_clicked(self, widget):
        Gtk.main_quit()

if __name__ == '__main__':
    gui = Gui()
    gui.connect("destroy", Gtk.main_quit)
    gui.show_all()
    Gtk.main()

