#include <gtk/gtk.h>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

struct AppData {
    GtkWidget *label;
};

gboolean randeazaCadru(gpointer data) {
    char *text_cadru = static_cast<char*>(data);
    return FALSE; 
}
struct CadruData {
    GtkWidget *label;
    string text;
};

gboolean aplicaTextInInterfata(gpointer data) {
    CadruData *c_data = static_cast<CadruData*>(data);
    
    string formatat = "<span font_family='Monospace' foreground='#333333'>" + c_data->text + "</span>";
    gtk_label_set_markup(GTK_LABEL(c_data->label), formatat.c_str());
    
    delete c_data; 
    return FALSE;
}

void buclaAnimatieGrafica(AppData *data) {
    this_thread::sleep_for(chrono::milliseconds(500));
    for (int i = 15; i >= 0; i--) {
        string cadru = "";
        
        for (int j = 0; j < i; j++) {
            cadru += "\n";
        }
        
        cadru += "      /\\_ _/\\\n";
        cadru += "     ( ᵢ ω ᵢ )\n"; 
        cadru += "      (っ🌷🌷 ⊂ )\n";
        cadru += "     (      )\n";
        cadru += "     '∪\"\"\"∪'\n";
        cadru += "       /V\\\n";
        
        cadru += (i % 2 == 0) ? "     * * *\n" : "       * *\n";

        CadruData *c_data = new CadruData();
        c_data->label = data->label;
        c_data->text = cadru;
        
        g_idle_add(aplicaTextInInterfata, c_data);
        
        this_thread::sleep_for(chrono::milliseconds(150));
    }
    
    CadruData *c_final = new CadruData();
    c_final->label = data->label;
    c_final->text = "\n\n\n  🌙 PISICA A AJUNS PE LUNA! 🚀\n\n    🌕 Hello World!🌎";
    g_idle_add([](gpointer data) -> gboolean {
        CadruData *cf = static_cast<CadruData*>(data);
        string ecran_final = "<span font_family='Sans' size='x-large' weight='bold' foreground='light blue'>" + cf->text + "</span>";
        gtk_label_set_markup(GTK_LABEL(cf->label), ecran_final.c_str());
        delete cf;
        return FALSE;
    }, c_final);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *label;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Pisica Spațială GTK");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 500); 
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    label = gtk_label_new(NULL);
    gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
    
    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_widget_show_all(window);

    AppData *data = g_new(AppData, 1);
    data->label = label;

    thread firAnimatie(buclaAnimatieGrafica, data);
    firAnimatie.detach();

    gtk_main();

    g_free(data);
    return 0;
}
