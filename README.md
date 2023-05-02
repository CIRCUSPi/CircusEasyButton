# **CircusEasyButton**
CircusEasyButton 是一個輕量級且高效率的按鈕控制 Library。該 Library 提供了低延遲且高效率的判斷方法，同時占用極低的運算資源。除此之外，該 Library 還提供了多種按鈕觸發模式，可依據使用者需求進行選擇。使用 CircusEasyButton 可以大大簡化程式碼，提高程式碼的可讀性。如果你需要一個輕量、高效、可定制化的按鈕控制 Library，CircusEasyButton 是一個不錯的選擇。
## **使用方式**

---

* ### **Include CircusButton Library**

    ```cpp
    #include <CircusButton.h>
    ```

* ### 建立 **CircusButton** Object

    建立一或多個 **CircusButton** Object，並在建構時傳入 Button IO Pin 以及觸發準位（0 or 1），建構函數將會將此 Pin 設為輸入上拉。

    ```cpp
    #define _BTN_A 4
    CircusButton buttonA(_BTN_A, 0); // IO4, 低準位觸發
    ```

* ### **定時輪巡**

    定時呼叫物件 loop 方法更新按鈕狀態，盡可能的即時呼叫此方法以獲得較高的響應速度，如下所示：

    ```cpp
    void loop()
    {
        buttonA.loop();
    }
    ```

* ### 檢查按鈕狀態

    目前按鈕觸發狀態共有 4 種，分別如下：

    | State code | Description |
    | --- | --- |
    | _KEYCODE_F_EDGE | 當按鈕由釋放到被壓下時觸發，觸發一次 |
    | _KEYCODE_REPEAT | 當按鈕持續壓下指定時間後觸發，重複觸發 |
    | _KEYCODE_PRESSED | 當按鈕被壓下時觸發，重複觸發 |
    | _KEYCODE_R_EDGE | 當按鈕由被壓下到釋放時觸發，觸發一次 |

    ```cpp
    void loop()
    {
        buttonA.loop();

            if (buttonA.readState() == _KEYCODE_F_EDGE) {
            Serial.println("BtnA_F_EDGE");
        } else if (buttonA.readState() == _KEYCODE_REPEAT) {
            Serial.println("BtnA_REPEAT");
        } else if (buttonA.readState() == _KEYCODE_PRESSED) {
            Serial.println("BtnA_PRESSED");
        } else if (buttonA.readState() == _KEYCODE_R_EDGE) {
            Serial.println("BtnA_R_EDGE");
        }
    }
    ```

* ### 其他設定

    此三項設定也可透過建構函數傳入設定，若未傳入則使用預設值。

    - 設定 Polling 間隔，單位 uS（預設為 50ms）
        
        ```cpp
        // Set Key Polling interval 50ms
        buttonA.SetTKeyPolling(50000UL);
        ```
        
    - 設定長按 ”首次觸發” 時間，單位 uS（預設為 1000ms）
        
        ```cpp
        // Set Key Repeat Start Time 1000ms
        buttonA.SetTKeyRepeatStart(1000000UL);
        ```
        
    - 設定長按 ”首次觸發後” 每次重複觸發時間間隔，單位 uS（預設為 300ms）
        
        ```cpp
        // Set Key Repeat Work Time 300ms
        buttonA.SetTKeyRepeatWork(300000UL);
        ```
        

## LICENSE

CircusEasyButton 基於 MIT 許可證發布。請參閱 LICENSE 文件以獲取更多詳細信息。
