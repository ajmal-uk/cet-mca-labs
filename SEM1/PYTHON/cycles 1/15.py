print("<==== Merge Dictionary ====>")

dict1 = {"A":1,"B":2,"C":3}
dict2 = {"E":4,"F":5}

m_dict = {**dict1,**dict2}

print(m_dict)