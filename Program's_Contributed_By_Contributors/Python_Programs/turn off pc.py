import os
import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from ttkthemes import ThemedStyle

#iniciar o programa com o pc em qualquer pc
def desligar_pc():
    tempo = entrada.get()
    unidade_tempo = escolha.get()
    
    if tempo.isdigit():
        tempo = int(tempo)
        if unidade_tempo == "Horas":
            tempo_em_segundos = tempo * 3600
        else:
            tempo_em_segundos = tempo * 60

        # Agendar o desligamento do PC
        os.system(f"shutdown -s -t {tempo_em_segundos}")

        messagebox.showinfo("Desligar PC", f"O PC será desligado em {tempo} {unidade_tempo}.")
        botao_desligar.config(state=tk.DISABLED)  # Desativa o botão Desligar
        botao_cancelar.config(state=tk.NORMAL)  # Ativa o botão Cancelar
    else:
        messagebox.showerror("Erro", "Digite um valor válido.")

def cancelar_desligamento():
    # Cancelar o desligamento do PC
    os.system("shutdown -a")

    messagebox.showinfo("Cancelar Desligamento", "O desligamento foi cancelado.")
    botao_desligar.config(state=tk.NORMAL)  # Ativa o botão Desligar
    botao_cancelar.config(state=tk.DISABLED)  # Desativa o botão Cancelar

# Crie a janela principal
janela = tk.Tk()
janela.title("Turn off")

#deixa a janela com o fundo preto
janela.configure(bg='#464646')

# Defina o tamanho fixo da janela
largura = 214
altura = 250
janela.geometry(f"{largura}x{altura}")

# Desabilite a opção de redimensionar a janela
janela.resizable(False, False)

# Personalize a barra de título usando o tema do ttkthemes
style = ThemedStyle(janela)
style.set_theme("equilux")  # Escolha o tema desejado, por exemplo, "arc"

# Crie um rótulo
rotulo = ttk.Label(janela, text="Digite o tempo:", font=('Arial', 12))
rotulo.grid(row=0, column=0, padx=10, pady=10)

# Crie uma entrada de texto
entrada = ttk.Entry(janela, font=('Arial', 12))
entrada.grid(row=1, column=0, padx=10, pady=10)

# Crie um rótulo para a escolha da unidade de tempo
#rotulo_unidade = ttk.Label(janela, text="Escolha a unidade de tempo:", font=('Arial', 12))
#rotulo_unidade.grid(row=2, column=0, padx=10, pady=5)

# Crie uma variável de controle para a escolha
escolha = tk.StringVar(janela)
escolha.set("Horas")  # Valor padrão

# Crie um menu de opções para a escolha da unidade de tempo
menu_opcoes = ttk.OptionMenu(janela, escolha,"", "Horas", "Minutos")
menu_opcoes.grid(row=3, column=0, padx=10, pady=10)

# Crie um botão para desligar o PC
botao_desligar = ttk.Button(janela, text="Desligar PC", command=desligar_pc)
botao_desligar.grid(row=4, column=0, padx=10, pady=10)
botao_desligar.configure(style="TButton")  # Personalize o botão


# Crie um botão para cancelar o desligamento
botao_cancelar = ttk.Button(janela, text="Cancelar", command=cancelar_desligamento)
#deixar o botao cancela do lado do de desligar
botao_cancelar.grid(row=5, column=0, padx=10, pady=10)
botao_cancelar.config(state=tk.DISABLED)  # Desativa o botão Cancelar inicialmente

# Inicie o loop da janela
janela.mainloop()