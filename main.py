import os
import pandas as pd

def INC(value):
  value = value.split('\n', 1)[0]
  wineDF = pd.read_csv('./vinhos.csv')
  wineDF = wineDF.query("ano_colheita == {}".format(value))

  open("{}.txt".format(value), 'w').close()

  txtfile = open("{}.txt".format(value), 'a')
  for index, row in wineDF.iterrows():
    linha = str(row['vinho_id']) + " " + str(row['rotulo']) + " " + str(row['ano_colheita']) + " " + str(row['tipo']) + "\n"
    txtfile.write(linha)
  txtfile.close()


def BUS(signal, value):
  # print('busca por ',signal, value)
  pass
def REM(value):
  # print('rem', value)
  pass


def lerInTxt(aux):
  with open('in.txt') as f:
    for line in f:
      command, value = line.split(':',1)
      aux+=command+" "+value
      if(command == 'INC'):
        INC(value)
      elif(command == 'REM'):
        REM(value)
      elif(command == 'BUS>'):
        BUS('>',value)
      elif(command == 'BUS<'):
        BUS('<',value)
      elif(command == 'BUS='):
        BUS('=',value)
  return aux
  
def main():
  aux = ""
  aux = lerInTxt(aux)
  print(aux)
  os.system("make")
  os.system("./main")
  
main()