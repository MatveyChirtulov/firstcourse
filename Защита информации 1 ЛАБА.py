import tkinter as tk
import random
import pyperclip
#У лукоморья дуб зелёный Златая цепь на дубе том: И днём и ночью кот учёный Всё ходит по цепи кругом;

# Глобальные переменные для таблиц
table1 = None
table2 = None

#Создание таблиц с символами
def CreateTable(alphabet):
    mas = [[],[],[],[],[],[]]
    counter = 0
    for i in range(0,6):
        for y in range(0,6):
            mas[i].append(list(alphabet)[counter])
            counter += 1
    for i in range(0,6):
        mas[i] = random.sample(mas[i], len(mas[i]))
        counter += 1
    return mas

#Проверка на наличие в таблице всех символов из предложения
def Check(alphabet,setMessage):
    flag = False
    for i in range(len(setMessage)):
        if setMessage[i] not in alphabet:
            for y in range(len(alphabet)):
                if alphabet[y] not in setMessage:
                    alphabet[y] = setMessage[i]
                    flag = True
                    break
    return alphabet

#Находим координаты символа из сообщения в нужной таблице
def FindCoord(Char,Table):
    line = 998
    for i in Table:
        column = 0
        line += 1
        if line == 999:
            line = 0
        for y in i:
            if Char == y:
                return [column,line]
            column += 1
    return "Отсутствует символ в алфавите"

#Составление биграммы по методу Уитстона
def Cipher(coord1,coord2,table1,table2):
    return table2[coord1[1]][coord2[0]]+table1[coord2[1]][coord1[0]]

def ReverseCipher(coord1,coord2,table1,table2):
    return table1[coord1[1]][coord2[0]]+table2[coord2[1]][coord1[0]]

#Шифрование целого сообщения методом Уитстона
def Wheatstone(message,table1, table2):
    result = ""
    for i in range(0,len(message),2):
        result += Cipher(FindCoord(message[i],table1),FindCoord(message[i+1],table2),table1,table2)
    return result

def ReverseWheatstone(message,table1,table2):
    result = ""
    for i in range(0,len(message),2):
        result += ReverseCipher(FindCoord(message[i],table2),FindCoord(message[i+1],table1),table1,table2)
    return result

#Копирование расшифрованного текста в буфер обмена
def CopyClipboard():
    window.clipboard_clear()  # Очистить буфер обмена
    window.clipboard_append(result_text.get('1.0',tk.END))# Добавить текст в буфер обмена

def InsertText():
    input_text.delete("1.0", tk.END)
    input_text.insert('1.0', pyperclip.paste())

def Clear():
    input_text.delete("1.0", tk.END)
# Функция для форматирования таблицы
def FormatTable(table):
    formatted = ""
    for row in table:
        formatted += " ".join(row) + "\n"
    return formatted

# GUI часть
def EncryptMessage():
    global table1, table2

    message = input_text.get("1.0", tk.END).strip()
    if len(message) % 2 == 1:
        message += "."
    
    alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ., "
    alphabet = random.sample(list(alphabet), len(alphabet))
    
    # Инициализация таблиц, если они ещё не созданы
    if table1 is None or table2 is None:
        alphabet = Check(alphabet, list(set(message)))
        table1 = CreateTable(alphabet)
        alphabet = random.sample(list(alphabet), len(alphabet))
        table2 = CreateTable(alphabet)
    
    encrypted_message = Wheatstone(message, table1, table2)
    
    # Вывод таблиц
    table1_text.delete("1.0", tk.END)
    table1_text.insert(tk.END, FormatTable(table1))
    
    table2_text.delete("1.0", tk.END)
    table2_text.insert(tk.END, FormatTable(table2))
    
    # Вывод зашифрованного сообщения
    result_text.delete("1.0", tk.END)
    result_text.insert(tk.END, encrypted_message)

def DecryptMessage():
    global table1, table2

    message = input_text.get("1.0", tk.END).strip()
    
    # Проверка, существуют ли таблицы, если нет, выводим предупреждение
    if table1 is None or table2 is None:
        result_text.delete("1.0", tk.END)
        result_text.insert(tk.END, "Таблицы не были сгенерированы. Сначала выполните шифрование.")
        return
    
    decrypted_message = ReverseWheatstone(message, table1, table2)
    
    # Вывод таблиц
    table1_text.delete("1.0", tk.END)
    table1_text.insert(tk.END, FormatTable(table1))
    
    table2_text.delete("1.0", tk.END)
    table2_text.insert(tk.END, FormatTable(table2))
    
    # Вывод расшифрованного сообщения
    result_text.delete("1.0", tk.END)
    result_text.insert(tk.END, decrypted_message)

# Создание основного окна
window = tk.Tk()
window.title("Шифрование методом Уитстона")

# Поле для ввода текста
input_label = tk.Label(window, text="Введите сообщение для шифрования/дешифрования:")
input_label.pack()

input_text = tk.Text(window, height=5, width=50)
input_text.pack()

# Кнопки для шифрования и дешифрования
encrypt_button = tk.Button(window, text="Зашифровать", command=EncryptMessage)
encrypt_button.pack()

decrypt_button = tk.Button(window, text="Расшифровать", command=DecryptMessage)
decrypt_button.pack()

copy_button = tk.Button(window, text='Скопировать текст вывода в буфер обмена', command=CopyClipboard)
copy_button.pack()
insert_button = tk.Button(window, text='Вставить скопированный текст в поле ввода', command=InsertText)
insert_button.pack()
clear_button = tk.Button(window, text  = 'Очистить поле ввода', command = Clear)
clear_button.pack()
# Поле для вывода таблицы 1
table1_label = tk.Label(window, text="Таблица 1:")
table1_label.pack()

table1_text = tk.Text(window, height=6, width=50)
table1_text.pack()

# Поле для вывода таблицы 2
table2_label = tk.Label(window, text="Таблица 2:")
table2_label.pack()

table2_text = tk.Text(window, height=6, width=50)
table2_text.pack()

# Поле для вывода результата
result_label = tk.Label(window, text="Результат:")
result_label.pack()

result_text = tk.Text(window, height=5, width=50)
result_text.pack()

# Запуск основного цикла программы
window.mainloop()

