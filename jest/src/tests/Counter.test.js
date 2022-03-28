import { render, screen } from "@testing-library/react";
import userEvent from "@testing-library/user-event";

import Counter from "../components/Counter";

describe("Counter", () => {
    it("render Counter", () => {
        render(<Counter />); // Counter 렌더링

        const target = screen.getByRole("button", { name: "+" }); // 요소 접근
        userEvent.click(target); // 이벤트 발생

        expect(screen.getByText("1")).toBeTruthy(); // 1 결과 확인
    });
});
