def numbers(password):
  if (not any(x.isdigit() for x in password)): return False
  
  for x1 in password:
    for x2 in password:
      if x1.isdigit() and x2.isdigit(): 
        d1 = int(x1)
        d2 = int(x2)

        if abs(d1 - d2) ==  1: return False
    
  return True

special_chars = {'.', '#', '$', '%', '/', '(', '&', ')'}
rules = [lambda s: any(x.isupper() for x in s),
         lambda s: any(x.islower() for x in s),
         lambda s: any(x in special_chars for x in s),
         lambda s: len(s) >= 10
         ]
