import socketserver
import _thread

HOST = "localhost"
PORT = 4242

if __name__ == "__main__":

    with socket.socket(socket.AF_INET, socket.SOCK_STEAM) as soc:
        s.connect((HOST, PORT))
        _thread.start_new_thread(lisen_msg)
        _thread.start_new_thread(send_msg)
