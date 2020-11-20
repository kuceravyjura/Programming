import json
with open('in.json', 'r') as x:
    file = json.load(x)
out = []
for task in file:
    userId = task['userId']
    completed = task['completed']
    selectedUser = None
    for user in out:
        if user['userId'] == userId:
            selectedUser = user
            break
    if selectedUser is None:
        selectedUser = {'userId': userId, 'task_completed': 0}
        out.append(selectedUser)
    if completed:
        selectedUser['task_completed'] += 1
with open('out.json', 'w') as x:
    x.write(json.dumps(out, indent=2))
