
data = []
with open('input','r') as f: 
	for i in f.readlines(): 
		data.append(int(i)) 

c = 0
print(sum(data,c))