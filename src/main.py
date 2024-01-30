import sys

data: list[str] = []
if len(sys.argv) >= 2:
	uargv = sys.argv
	uargv.pop(0)
	for a in uargv:
		data.append(a.replace("\\\\s", " "))

def main():
	print(data)

if __name__ == "__main__":
    main()