在安卓开发中，确实存在许多用于网络通信的API。以下是Android系统内建和广泛使用的网络通信相关API和技术：

1. **HttpURLConnection**：
   - 这是Android内置的标准Java API，用于执行HTTP请求。开发者可以直接使用`java.net.HttpURLConnection`类发送GET、POST等各种HTTP请求，并处理响应。

2. **OkHttp**：
   - 一个高效的HTTP客户端库，由Square公司开发，现已成为很多Android项目首选的HTTP通信库，其特点在于对HTTP/2、SPDY、连接复用、失败重试等方面有优秀支持，并且易于使用。

3. **Retrofit**：
   - 一个基于Square公司的OkHttp构建的RESTful API客户端库，提供了更加简洁易用的API定义和调用方式，尤其适合进行JSON格式的数据交换。

4. **Volley**：
   - Google官方推出的网络请求库，特别注重图像加载和网络请求的批处理，适用于频繁的小型网络数据请求。

5. **AndroidNetworking**：
   - 另一个第三方库，简化了HTTP请求和图片加载，支持多种请求类型和回调模式。

6. **Socket通信**：
   - 使用Java标准库中的`java.net.Socket`和`java.net.ServerSocket`类进行TCP/IP网络通信，适用于需要长连接或者低层网络控制的场景。

7. **DatagramSocket**：
   - 对于UDP通信，可以使用`java.net.DatagramSocket`和`java.net.DatagramPacket`进行无连接的数据报文传输。

8. **WebSocket**：
   - 安卓支持WebSocket协议，可以通过第三方库如AutobahnAndroid、Java-WebSocket等实现WebSocket通信。

此外，如果你的应用需要更底层或者更复杂的网络通信机制，还可以结合JNI（Java Native Interface）调用C/C++编写的网络库，或者使用NDK（Native Development Kit）直接编写原生代码实现网络功能。不过这通常发生在有特殊需求或性能要求极高的情况下。