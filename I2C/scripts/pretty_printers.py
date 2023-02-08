import gdb 


class registerPrinter:
	def __init__(self, val):
		self.val = val

	def to_string(self):
		x = self.val
		return '{}'.format(x)


def my_pretty_printers(val):
	#if str(val.type) == ('volatile uint32_t'): 
	#	return registerPrinter(val)
	  #print(dir(val))
	return None

gdb.pretty_printers.append(my_pretty_printers)