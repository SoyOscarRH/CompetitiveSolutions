import string
import itertools

print([''.join(x) for x in itertools.product('ABCDEFGHIJKLMNOPQRSTUVWXYZ', repeat=50)])