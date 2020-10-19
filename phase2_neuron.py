import numpy as np

# Caleb Burke
# Ben Leone
# Created using https://www.kdnuggets.com/2019/11/build-artificial-neural-network-scratch-part-1.html
# As a reference

#   This is not a good use for this type of machine learning
#   as the article below shows
#   https://www.usnews.com/education/best-colleges/articles/2019-09-10/how-colleges-choose-which-students-to-admit?rec-type=sailthru
#   but just a general use case implementation of the concepts
#   This neuron and neural network will predict if a person will
#   get admission to a certain college by output 1 or be denied
#   admission by output 0

# Independent variables
# This is the training data based
# on survey data from students
# that applied to a certain school and
# were either accepted or denied admission


# Each array represents a person and the values are either yes=1 or no=0 answers to 3 questions
# This of course will scale to any number of inputs

# Question 1 Did they score above a certain value on SAT test
# Question 2 Do themselves or their parents have over set value in assets
# Question 3 Was their gpa over a certain score in high school

input_set = np.array([[0, 1, 0],
                      [0, 0, 1],
                      [1, 0, 0],
                      [1, 1, 0],
                      [1, 1, 1],
                      [0, 1, 1],
                      [0, 1, 0]])
# Dependent variable

# This array represents the answer to the question of did the 7 people get into
# the school based on their answers
labels = np.array([[1,
                    0,
                    0,
                    1,
                    1,
                    0,
                    1]])
labels = labels.reshape(7, 1)  # to convert labels to vector

# initialize weights with random seed but also notice intuitivley that the machine
# will learn to put a higher weight on the second column as more output 1s have been produced by
# more ones in that array position

np.random.seed(42)
weights = np.random.rand(3, 1)
bias = np.random.rand(1)
lr = 0.05  # learning rate

# define activation function to smooth out the output
# without this function the ouput would be a zero or a one and have a large inpact on the
# next neuron


def sigmoid(x):
    return 1/(1+np.exp(-x))


def sigmoid_derivative(x):
    return sigmoid(x)*(1-sigmoid(x))

# now train the model 25K times


for epoch in range(25000):
    inputs = input_set
    # This feed the data through one neuron 25000 times
    XW = np.dot(inputs, weights) + bias
    z = sigmoid(XW)  # This is the smoothing fuction so the output can be
    # A number between 1 and 0 not just 1 and zero which helps with output swings
    error = z - labels
    # print(error.sum())    ############Suppress error output for now
    dcost = error
    dpred = sigmoid_derivative(z)
    z_del = dcost * dpred
    inputs = input_set.T
    weights = weights - lr*np.dot(inputs, z_del)

    for num in z_del:
        bias = bias - lr*num

# now we can make predictions about if the student will get into the college based on the training
# data and answers specific to this person

print("This is the chance the person A who scored well on the SAT and who has money will get accepted to this university")
# This array represents the persons individual answers to questions.
single_pt = np.array([1, 1, 0])
# This person or parents have over a certain value in assets
result = sigmoid(np.dot(single_pt, weights) + bias)
# and scored well on the SAT
print(result)

# Now run the example with another person
print("This is the chance the person B who scored well on the SAT will get accepted to this university")
single_pt = np.array([1, 0, 0])  # This person scored well on the SAT
result = sigmoid(np.dot(single_pt, weights) + bias)
print(result)

print("This is the chance the person C who has money and had a good GPA will get accepted to this university")
# This has the required assets and had a high gpa in high school.
single_pt = np.array([0, 1, 1])
result = sigmoid(np.dot(single_pt, weights) + bias)
print(result)

print("This is the chance the person D who has no money, didnt do well on the")
print("SAT and didnt have a good GPA in high school will get accepted to this university")
# This array represents the persons individuall answers to questions.
single_pt = np.array([0, 0, 0])
result = sigmoid(np.dot(single_pt, weights) + bias)
print(result)

print("This is the chance the person E who has money will get accepted to this university")
# This array represents the persons individuall answers to questions.
single_pt = np.array([0, 1, 0])
result = sigmoid(np.dot(single_pt, weights) + bias)
print(result)
