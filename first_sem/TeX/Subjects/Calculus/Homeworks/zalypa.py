from latex2sympy2 import set_real
set_real(False)

tex = r'(3-i)\cdot x +(4+2\cdot i)\cdot y=2+6\cdot i'
latex2sympy(tex)

print(tex)