import tkinter as tk

def  calculate_bmi() :
    weight = float(weight_entry.get())
    height = float(weight_entry.get())
    bmi = round(weight / (height ** 2), 2)
    bmi_label.config(text=f"BMI : {bmi}") 

root = tk.TK
root.title("BMI Calculator")

weight_label = tk.Label(root, text ="Weight (kg):")
weight_label.grid(row = 0 , column = 0)
weight_entry = tk.Entry(root)
weight_entry.grid(row= 0 , column = 1)

height_label = tk.Label(root, text ="Height (kg):")
height_label.grid(row = 1 , column = 0)
height_entry = tk.Entry(root)
height_entry.grid(row= 1 , column = 1)

calc_button = tk.Button(root, text="Calculate BMI" , command=calculate_bmi)
calc_button.grid(row = 2 , column = 0 , columnspan=2)

bmi_label = tk.Label(root, text="BMI : ")
bmi_label.grid(row=3 , column=0 , columnspan= 2)