import { StyledItem } from "./Item.style";

export interface ItemProps {
  value: number;
  height: number;
  offset: number;
}

const Item = ({ value, height, offset }: ItemProps) => {
  return (
    <StyledItem height={height} offset={offset}>
      {value}
    </StyledItem>
  );
};

export default Item;
