class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class List:
    def __init__(self):
        self.head = None
        self.count = 0

    def __del__(self):
        current = self.head
        while self.head:
            self.head = self.delete_node(self.head)
            if self.head == current:
                break

    def add(self, obj):
        new_node = Node(obj)
        if self.head is None:
            self.head = new_node
            self.head.next = self.head
            self.head.prev = self.head
        else:
            new_node.next = self.head
            new_node.prev = self.head.prev
            self.head.prev.next = new_node
            self.head.prev = new_node
        self.count += 1

    def delete_node(self, node):
        if node is None:
            return None

        if node.next == node:
            self.head = None
            return None

        node.prev.next = node.next
        node.next.prev = node.prev
        if self.head == node:
            self.head = node.next

        self.count -= 1
        return node.next

    def traverse(self, callback):
        if not self.head:
            print("List is empty, there is nothing to work with.")
            return

        current = self.head
        while True:
            callback(current.data)
            current = current.next
            if current == self.head:
                break

    def delete_conditional(self, condition):
        if not self.head:
            print("List is empty, there is nothing to work with.")
            return

        temp_count = self.count
        for _ in range(temp_count):
            if condition(self.head.data):
                self.head = self.delete_node(self.head)
            else:
                self.head = self.head.next
