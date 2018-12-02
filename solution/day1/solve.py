
with open('input','r') as f:
	data = f.readlines()

frequency = 0 

for i in data:
	op = i[0]
	number = int(i[1:-1])
	if op == "+":
		frequency += number
	elif op == "-":
		frequency -= number

print(frequency)