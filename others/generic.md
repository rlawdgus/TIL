## Generic

```typescript
interface SelectedItem {
    selected: boolean;
}

interface CheckedItem {
    checked: boolean;
}

type Overlay = SelectedItem | CheckedItem;

// T는 변수처럼 동작하고 Overlay를 상속받는다.
// T는 item에 해당하는 변수의 타입이고 selected | checked를 갖고 있을 것이다.
// item을 반환하므로 이 함수의 반환 타입은 item에 해당하는 변수의 타입이다.
const func = <T extends Overlay>(item: T) => ({ ...item });
```
