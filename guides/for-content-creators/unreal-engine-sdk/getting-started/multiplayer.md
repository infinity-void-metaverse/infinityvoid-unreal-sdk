---
cover: >-
  https://images.unsplash.com/photo-1542751371-adc38448a05e?crop=entropy&cs=tinysrgb&fm=jpg&ixid=MnwxOTcwMjR8MHwxfHNlYXJjaHwzfHxnYW1pbmd8ZW58MHx8fHwxNjYzOTI1MzI5&ixlib=rb-1.2.1&q=80
coverY: 0
---

# Interactable Elements

**Infinity Void SDK** offers built-in functionality for enabling interaction with elements within your scene. To make actors interactable, there are two methods available:

### **BP\_InteractableBaseChild**

This blueprint simplifies the process of creating interactive elements in your scene. Here are the steps to make an actor interactable:

a. Duplicate the BP\_InteractableBaseChild blueprint.

<figure><img src="../../../../.gitbook/assets/duplicate.png" alt=""><figcaption></figcaption></figure>

b. Open the blueprint editor.

c. Select the visual mesh you want to make interactable.

<figure><img src="../../../../.gitbook/assets/visual mesh.png" alt=""><figcaption></figcaption></figure>

d. Drag and drop the actor into your scene.

Inside the blueprint, you have the flexibility to:

* Add custom logic for interactions.

<figure><img src="../../../../.gitbook/assets/logic.png" alt=""><figcaption></figcaption></figure>

* Modify the displayed text when the user aims at the object.
* Toggle interactability using a boolean, which can be useful for scenarios where you want to restrict user interaction with the actor based on certain events or conditions.

<figure><img src="../../../../.gitbook/assets/Options IV.png" alt=""><figcaption></figcaption></figure>

