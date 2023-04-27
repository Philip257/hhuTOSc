/*****************************************************************************
 *                                                                           *
 *                                    C G A                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * Beschreibung:    Mit Hilfe dieser Klasse kann man auf den Bildschirm des  *
 *                  PCs zugreifen. Der Zugriff erfolgt direkt auf der Hard-  *
 *                  wareebene, d.h. ueber den Bildschirmspeicher und den     *
 *                  I/O-Ports der Grafikkarte.                               *
 *                                                                           *
 * Autor:           Olaf Spinczyk, TU Dortmund                               *
 *                  Aenderungen von Michael Schoettner, HHU, 21.8.2016       *
 *****************************************************************************/
#include "devices/CGA.h"

/*****************************************************************************
 * Methode:         CGA::setpos                                              *
 *---------------------------------------------------------------------------*
 * Beschreibung:    Setzen des Cursors in Spalte x und Zeile y.              *
 *****************************************************************************/
void CGA::setpos(int x, int y)
{
    unsigned short pos = x + y * COLUMNS;
    index_port.outb(14);
    data_port.outb(pos >> 8);
    index_port.outb(15);
    data_port.outb(pos & 0xff);
}

/*****************************************************************************
 * Methode:         CGA::getpos                                              *
 *---------------------------------------------------------------------------*
 * Beschreibung:    Abfragem der Cursorposition                              *
 *                                                                           *
 * Rückgabewerte:   x und y                                                  *
 *****************************************************************************/
void CGA::getpos(int &x, int &y)
{
    index_port.outb(14);
    unsigned short high = data_port.inb();
    index_port.outb(15);
    unsigned short low = data_port.inb();
    unsigned short pos = (high << 8) | low;
    x = pos % COLUMNS;
    y = (int)pos / COLUMNS;
}

/*****************************************************************************
 * Methode:         CGA::show                                                *
 *---------------------------------------------------------------------------*
 * Beschreibung:    Anzeige eines Zeichens mit Attribut an einer bestimmten  *
 *                  Stelle auf dem Bildschirm.                               *
 *                                                                           *
 * Parameter:                                                                *
 *      x,y         Position des Zeichens                                    *
 *      character   Das auszugebende Zeichen                                 *
 *      attrib      Attributbyte fuer das Zeichen                            *
 *****************************************************************************/
void CGA::show(int x, int y, char character, unsigned char attrib){
    char *pos;
    char *CGA_START = (char*)0xb8000;
    pos = CGA_START + 2 * (x + y * COLUMNS);
    *pos = character;
    *(pos + 1) = attrib;
}

/*****************************************************************************
 * Methode:         CGA::print                                               *
 *---------------------------------------------------------------------------*
 * Beschreibung:    Anzeige von 'n' Zeichen ab der aktuellen Cursorposition  *
 *                  '\n' fuer Zeilenvorschub.                                *
 *                                                                           *
 * Parameter:                                                                *
 *      string      Auszugebende Zeichenkette                                *
 *      n           Laenger der Zeichenkette                                 *
 *      attrib      Attributbyte fuer alle Zeichen der Zeichenkette          *
 *****************************************************************************/
void CGA::print(char *string, int n, unsigned char attrib){
    int x, y;
    getpos(x, y);
    for (int i = 0; i < n; i++){
        bool nextLine = false;
        if ('\n' == string[i]){
            nextLine = true;
        }else{
            show(x, y, string[i], attrib);
        }

        if (x < COLUMNS){
            x++;
        }else nextLine = true;

        if (nextLine){
            if (y < ROWS){
                y++;
                x = 0;
            } else {
                scrollup();
                x = 0;
            }
        }
        setpos(x, y);
    }
}

/*****************************************************************************
 * Methode:         CGA::scrollup                                            *
 *---------------------------------------------------------------------------*
 * Beschreibung:    Verschiebt den Bildschirminhalt um eine Zeile nach oben. *
 *                  Die neue Zeile am unteren Bildrand wird mit Leerzeichen  *
 *                  gefuellt.                                                *
 *****************************************************************************/
void CGA::scrollup(){

}

/*****************************************************************************
 * Methode:         CGA::clear                                               *
 *---------------------------------------------------------------------------*
 * Beschreibung:    Lösche den Textbildschirm.                               *
 *****************************************************************************/
void CGA::clear(){
    
}

/*****************************************************************************
 * Methode:         CGA::attribute                                           *
 *---------------------------------------------------------------------------*
 * Beschreibung:    Hilfsfunktion zur Erzeugung eines Attribut-Bytes aus     *
 *                  Hintergrund- und Vordergrundfarbe und der Angabe, ob das *
 *                  Zeichen blinkend darzustellen ist.                       *
 *                                                                           *
 * Parameter:                                                                *
 *      bg          Background color                                         *
 *      fg          Foreground color                                         *
 *      blink       ywa/no                                                   *
 *****************************************************************************/
unsigned char CGA::attribute(CGA::color bg, CGA::color fg, bool blink){

}
