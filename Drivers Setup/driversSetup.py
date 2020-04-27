import os 
from rawString import raw
from time import sleep
from datetime import date
import re 

'''
/** Driver Setup Environment **/
'''
#Header information
author = "Alzahraa Elsallakh"
version = "V01"
creationDate = date.today().strftime("%d %b %Y")

driverName = ""
driverLayer = ""

requiredFiles = []
requiredFilesMCAL = ['_program.c','_interface.h','_config.h','_register.h','_private.h']
requiredFilesHAL = ['_program.c','_interface.h','_config.h','_private.h']
requiredFilesOS = ['_program.c','_interface.h','_config.h','_private.h']
requiredFilesLIB = ['.h']
requiredFilesAPP = ['.c']

libraries = []

def setupEnvironment():
  global driverLayer
  #Swapping to COTS Folder
  cots = os.getenv('COTS')
  os.chdir(raw(cots))
  
  setLibraries()
  
  #Choosing Driver's Layer
  layers = os.listdir()
  for layer in layers:
    print(layer)
  chosenLayer = input("Enter Layer Number\n")
  driverLayer = layers[int(chosenLayer)-1].split('-')[1]
  os.chdir(layers[int(chosenLayer)-1])
  
  # Choosing Microcontroller
  if int(chosenLayer) == 1:
    layers = os.listdir()
    for layer in layers:
      print(layer)
    chosenController = input("Enter Controller Number\n")
    os.chdir(layers[int(chosenController)-1])
    

  #Creating Driver's Folder
  status = createFolder()
  
  return status

def createFolder():

  #Checking for Driver's Multiple Definition 
  listDirectories = os.listdir()
  existedDrivers=[]
  for dir in listDirectories:
    existedDrivers.append(dir.split('-')[1])
  if driverName in existedDrivers:
    print("Multiple definition for the same driver!")
    status = 'existed'
    return status
    
  #Appending Driver's Number to its Name
  countDrivers = str(len(listDirectories) + 1)
  if int(countDrivers) < 10:
    countDrivers = '0'+ countDrivers
  driverNameWithCount = countDrivers +'-'+ driverName
  
  #Creating Driver's Directory and Changing Directory to it 
  os.mkdir(driverNameWithCount)
  os.chdir('./'+driverNameWithCount)
  status = 'created'
 
  return status

def createFiles():
  global requiredFiles
  
  #Creating Required Files for driver depending on its layer
  if driverLayer == "MCAL":
    requiredFiles = requiredFilesMCAL
  elif driverLayer == "HAL":
    requiredFiles = requiredFilesHAL
  elif driverLayer == "LIB":
    requiredFiles = requiredFilesLIB
  elif driverLayer == "APP":
    requiredFiles = requiredFilesAPP
  elif driverLayer == "OS":
    requiredFiles = requiredFilesOS
   
  for file in requiredFiles:
    fileName = driverName+file
    opened = open(fileName,'w')
    
    
    #Adding file header     
    container = "/************************************************/\n"
    lineWidth = len(container) 
    authorLine = "Author: " + author
    versionLine = "Version: " + version
    dateLine = "Date: " + creationDate
    layerLine = "Layer: " + driverLayer
    componentLine = "Component: " + driverName
    fileNameLine = "File Name: " + fileName
    lines = [authorLine, versionLine, dateLine , layerLine , componentLine, fileNameLine]
    
    opened.write(container)
    for line in lines:
      line = '/* ' + line
      while (len(line) < (lineWidth - 3)):
        line = line + ' '
      line = line + '*/\n'
      opened.write(line)
    opened.write(container)
    opened.write('\n')
    
    initFunctiton = '''\n\n/*
    Description: This function shall initiate '''+driverName+'''
    Input: void
    output: STD_TYPES_ERROR
*/    
extern STD_TYPES_ERROR '''+driverName+'''_errInit (void);\n\n
'''
    
    #Adding file guard to headers
    if (file.split('.')[1] == "h"):
      fileName = fileName.replace('.','_')
      fileName = fileName.upper()
      opened.write('#ifndef '+fileName+'\n')
      opened.write('#define '+fileName+'\n\n')
      if (fileName.split('_')[1] == "INTERFACE"):
        opened.write(initFunctiton)
      opened.write('#endif\n')
    opened.close()

def setLibraries():
  
  #Saving Original Path
  callePath = os.getcwd()
  
  #Changing Directory to COTS Library 
  librariesFolder = '04-LIB'
  os.chdir(librariesFolder)
  
  #Determining Existed Libraries in COTS
  for lib in os.listdir():
    os.chdir(lib)
    #Appending only header files
    for libFile in os.listdir():
      if (libFile.split('.')[1] == "h"):
        libraries.append(libFile)
    os.chdir("../")
    
  #Returning Back to Original Path
  os.chdir(callePath)

# Editing program file by adding includes and init functions
def editFiles():
   
   
  initFunctiton = '''\n\n/*
    Description: This function shall initiate '''+driverName+'''
    Input: void
    output: STD_TYPES_ERROR
*/    
STD_TYPES_ERROR '''+driverName+'''_errInit (void)\n{\n\n\n}\n\n
'''
   
  #Adding required driver incluedes depending on its layer
  if driverLayer == "MCAL" or driverLayer == "HAL" or driverLayer == "OS":
  
    includedFiles = [incFile for incFile in requiredFiles if incFile != '_program.c']
    
    progName = driverName+'_program.c'
    prog = open(progName,'a')
    #Including libraries
    for lib in libraries:
      prog.write('#include "'+lib+'"\n')
    prog.write('\n')
    #Including driver headers
    for includedFile in includedFiles:
      prog.write('#include "'+driverName+includedFile+'"\n')
    
    prog.write(initFunctiton)
    prog.close()

    
def main():
  global driverName
  driverName = input("Enter Driver's Name:\n").upper()
  status = setupEnvironment()
  if status == 'created':
    createFiles()
    editFiles()
    print("Congrats.. Driver is ready")
  sleep(3)

if __name__ == '__main__':
  main()  