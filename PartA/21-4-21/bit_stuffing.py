
def sender(stream):
    '''
    stuffing will happen at the sender
    '''

    print("Stuffing the stream entered...\n\n")

    stuffed = stream.replace("011111", "0111110")

    
    print(f"Stuffed stream is: {stuffed}\n\n")
    return stuffed


def receiver(stuffed):
    '''
    unstuffing will happen at the receiver
    '''

    print("Unstuffing the stream entered...\n\n")

    unstuffed = stuffed.replace("0111110", "011111")

    print(f"Unstuffed stream is: {unstuffed}\n\n")

    return unstuffed

        
def main():
    stream = input("Enter a sequence of bits:\n")

    stuffed_message = sender(stream)

    print("Receiver has received the message\n\n")

    unstuffed_message = receiver(stuffed_message)

    print("DONE")




if __name__ == "__main__":
    main()

# some inputs for the program
# 010111111001
# 01101111111001111101111111111000000
