import styled from "@emotion/styled";

interface StyledListProps {
  height: number;
}

export const StyledList = styled.ul<StyledListProps>`
  position: relative;
  width: 100%;
  height: ${({ height }) => height}px;
`;

interface ItemProps {
  height: number;
  offset: number;
}

export const StyledItem = styled.li<ItemProps>`
  position: absolute;
  top: ${({ offset }) => offset}px;
  width: 200px;
  height: ${({ height }) => height}px;

  display: flex;
  justify-content: center;
  align-items: center;

  border-bottom: 1px solid salmon;

  &:first-of-type {
    border-top: 1px solid salmon;
  }
`;
