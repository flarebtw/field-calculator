#include <gtk-3.0/gtk/gtk.h>
#include "../include/FieldCalculator.h"

// Виджеты
GtkWidget *window;
GtkWidget *p_entry;
GtkWidget *a_entry;
GtkWidget *b_entry;
GtkWidget *result_label;
GtkComboBoxText *type_combo;

// Обработчик кнопки "Рассчитать"
void on_calculate(GtkWidget *widget, gpointer data) {
    const char *p_text = gtk_entry_get_text(GTK_ENTRY(p_entry));
    int p = atoi(p_text);
    
    if (p <= 1) {
        GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(window), 
            GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, 
            "Ошибка: p должно быть > 1");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    int choice = gtk_combo_box_get_active(GTK_COMBO_BOX(type_combo));
    const char *result_text;

    if (choice == 0) { // Дробь
        int a = atoi(gtk_entry_get_text(GTK_ENTRY(a_entry)));
        int b = atoi(gtk_entry_get_text(GTK_ENTRY(b_entry)));
        
        if (b == 0) {
            result_text = "Ошибка: знаменатель не может быть 0";
        } else {
            int x = getX(a, b, p);
            result_text = g_strdup_printf("%d/%d в поле %d = %d", a, b, p, x);
        }
    } else { // Целое число
        int number = atoi(gtk_entry_get_text(GTK_ENTRY(a_entry)));
        int element = getElementInField(number, p);
        result_text = g_strdup_printf("%d в поле %d = %d", number, p, element);
    }

    gtk_label_set_text(GTK_LABEL(result_label), result_text);
}

// Инициализация GUI
void build_gui(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Калькулятор поля");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

    // Поле для p
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Порядок поля (p):"), 0, 0, 1, 1);
    p_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), p_entry, 1, 0, 1, 1);

    // Выбор типа
    type_combo = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    gtk_combo_box_text_append_text(type_combo, "Дробь");
    gtk_combo_box_text_append_text(type_combo, "Целое число");
    gtk_combo_box_set_active(GTK_COMBO_BOX(type_combo), 0);
    gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(type_combo), 0, 1, 2, 1);

    // Поля для a и b
    a_entry = gtk_entry_new();
    b_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Числитель (a):"), 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), a_entry, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Знаменатель (b):"), 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), b_entry, 1, 3, 1, 1);

    // Кнопка и результат
    GtkWidget *calculate_btn = gtk_button_new_with_label("Рассчитать");
    g_signal_connect(calculate_btn, "clicked", G_CALLBACK(on_calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), calculate_btn, 0, 4, 2, 1);

    result_label = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 5, 2, 1);

    gtk_container_add(GTK_CONTAINER(window), grid);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();
}

int main(int argc, char *argv[]) {
    build_gui(argc, argv);
    return 0;
}