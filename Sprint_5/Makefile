neuron: neuron_test.c neuron.c
	gcc neuron_test.c neuron.c -lm -o neuron.o

network: network.c neuron.c
	gcc network.c neuron.c -lm -o network.o

clean:
	rm *.o