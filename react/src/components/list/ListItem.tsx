import { Draggable } from "react-beautiful-dnd";

import { StyledListItem } from "../_styledComponent";

interface ListItemProps {
    id: string;
    name: string;
    index: number;
}

const ListItem = ({ id, name, index }: ListItemProps) => {
    return (
        <Draggable draggableId={id} index={index}>
            {(provided) => (
                <StyledListItem
                    {...provided.draggableProps}
                    {...provided.dragHandleProps}
                    ref={provided.innerRef}
                >
                    {name}
                </StyledListItem>
            )}
        </Draggable>
    );
};

export default ListItem;
