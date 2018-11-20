from firebase import firebase

firebase = firebase.FirebaseApplication('https://rawmateriallocalization.firebaseio.com')

#result = firebase.get('',None)
for i in 0,10 :
    material_code = 'M10572' + str(i)
    s = str(i)
    firebase.post('/',{material_code:s})

#print(result)

#note
# Libs/site-pcages/ _init_ .py(3rd line) and firebase.py (12th line) is commented as #from .async import process_pool