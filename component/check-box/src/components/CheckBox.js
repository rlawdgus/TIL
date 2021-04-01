import React from 'react'
import CheckIcon from './CheckIcon'

const CheckBox = ({ checked, onClick }) => {
    const checkedClass = checked ? "checked" : ""

    return (
        <div className={"check-box " + checkedClass} onClick={onClick} >
            <CheckIcon />
        </div>
    )
}

export default CheckBox