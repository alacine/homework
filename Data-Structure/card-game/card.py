card = []

for i in range(0, 54):
    card.append(0)
    # print(card[i])

for i in range(2, 54):
    for j in range(i, 54, i):
        card[j] = ~card[j]

for i in range(1, 54):
    if card[i] == 0:
        print(i,"",end = "")
