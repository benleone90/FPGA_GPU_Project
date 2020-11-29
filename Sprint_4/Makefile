neuron: neuron_test.c neuron.c
	gcc neuron_test.c neuron.c -o neuron.o

network: network.c neuron.c
	gcc network.c neuron.c -o network.o

clean:
	rm *.o