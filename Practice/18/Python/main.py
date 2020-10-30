import string
word = "halloklempnerdasistfantastischfluggegecheimen"
length = len(word)

chances = {}
count = {}

for letter in string.ascii_lowercase:
    chances[letter] = count[letter] = 0

for char in word:
    count[char] += 1
for char in count:
    chances[char] = count[char] / length
word = input()
chance = chances[word[0]]
if chance == 0:
    print('Сигизмунду не знакома буква в стоп слове')
    exit()
x = chance
for i in range(1, len(word)):
    if chances[word[i]] == 0.0:
        if x == 0.0:
            print('Сигизмунду не знакома буква в стоп слове')
            exit()
        else:
            chance = x * chance
    else:
        chance = chance * chances[word[i]]
        x = chance
print(chance)