#!/usr/bin/python3
"""Fetch all tasks from all employees and export in json format"""
import json
import requests

base_url = 'https://jsonplaceholder.typicode.com'

if __name__ == '__main__':

    users_url = '{}/users'.format(base_url)
    # get info from api
    response = requests.get(users_url)
    # pull data from api
    data = response.text
    # parse the data into json format
    data = json.loads(data)

    # extract users data
    builder = {}
    for user in data:
        # print("id is: {}".format(user_id))
        user_id = user.get('id')
        # print("username is: {}".format(user_name))
        user_name = user.get('username')
        # print("dict_key: {}".format(dict_key))
        dict_key = str(user_id)
        # get user info about todo tasks
        # ex: https://jsonplaceholder.typicode.com/users/1/todos
        builder[dict_key] = []
        # print("tasks url is: {}".format(tasks_url))
        tasks_url = '{}/todos?userId={}'.format(base_url, user_id)

        # get info from api
        response = requests.get(tasks_url)
        # pull data from api
        tasks = response.text
        # parse the data into JSON format
        # prrint("JSON LOADS IS: {}".format(tasks))
        tasks = json.loads(tasks)

        for task in tasks:
            json_data = {
                "task": task['title'],
                "completed": task['completed'],
                "username": user_name
            }
            # append dictionary key to the dictionary
            builder[dict_key].append(json_data)
    # write the data to the file
    json_encoded_data = json.dumps(builder)
    with open('todo_all_employees.json', 'w', encoding='UTF8') as myFile:
        myFile.write(json_encoded_data)
