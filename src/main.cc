#include <saucer/smartview.hpp>
#include <Windows.h>
std::string script = R"(
        function injectTimer() {
            if (!document.getElementById('study-timer')) {
                let timerDiv = document.createElement('div');
                timerDiv.id = 'study-timer';
                timerDiv.style = 'position:fixed;bottom:10px;right:10px;padding:10px;background:#222;color:#fff;font-size:20px;z-index:9999;border-radius:5px;';
                document.body.appendChild(timerDiv);
            }

            let endTime = localStorage.getItem('study-end-time');
            if (!endTime) {
                endTime = Date.now() + (90 * 60 * 1000);
                localStorage.setItem('study-end-time', endTime);
            }

            function updateTimer() {
                let remaining = endTime - Date.now();
                if (remaining <= 0) {
                    document.getElementById('study-timer').innerHTML = 'Session Complete!';
                } else {
                    let min = Math.floor(remaining / 60000);
                    let sec = Math.floor((remaining % 60000) / 1000);
                    document.getElementById('study-timer').innerHTML = `Time Left: ${min}m ${sec}s`;
                }
            }
            updateTimer();
        }

        setInterval(() => {
            injectTimer();
            }, 100);
            )";
void setFullscreen(HWND hwnd)
{
    if (hwnd)
    {
        SetWindowLong(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE); // Remove borders
        ShowWindow(hwnd, SW_MAXIMIZE);                         // Maximize window
    }
}

HWND getSaucerWindow()
{
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Wait for the window to appear
    return FindWindow(NULL, "focus");                     // Change "Study Mode" to your actual title
}

int main()
{
    auto app = saucer::application::init({
        // Instantiate application
        .id = "focus", // Choose a suitable ID for your program
    });

    saucer::smartview smartview{{
        // Instantiate smartview
        .application = app,
    }};
    smartview.set_title("focus"); // Set the window title to "Hello World!"
    // smartview.set_decorations(false);
    smartview.set_force_dark_mode(true);
    smartview.set_always_on_top(true);
    // Expose a synchronous native function "add_ten" using the default serializer
    smartview.expose("add_ten", [](int i)
                     { return i + 10; });

    smartview.set_url("https://google.com"); // Navigate to google.com
    smartview.show();                        // Show the smartview
    smartview.inject({
        .code = script,
        .time = saucer::load_time::ready,
    });
    HWND hwnd = getSaucerWindow();
    setFullscreen(hwnd);
    app->run(); // And finally enter the run-loop.

    return 0;
}