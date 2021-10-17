import React, {useMemo} from 'react';
import { useTable } from 'react-table';
import DOC from './DOC.json';
import {Dcol} from './Dcol';
import './DTstyle.css';


export const Dtable = ()=>{
    const columns  = useMemo(() => Dcol,[]);
    const data = useMemo(()=> DOC, []);
    const tableInstance = useTable({columns, data});

    const {getTableProps, getTableBodyProps, headerGroups, rows, prepareRow} = tableInstance;


    return (
        <table {...getTableProps()}>
            <thead>
                {
                    headerGroups.map((headerGroup)=>(
                        <tr {...headerGroup.getHeaderGroupProps()}>
                            {
                                headerGroup.headers.map(column =>(
                                    <th {...column.getHeaderProps()}>
                                        {column.render('Header')}
                                    </th>
                                ))
                            }
                            
                        </tr>
                     ))
                }
                
            </thead>
            <tbody {...getTableBodyProps()}>
                {
                    rows.map(row =>{
                        prepareRow(row)
                        return(
                            <tr {...row.getRowProps()}>
                                {
                                    row.cells.map(cell =>{
                                        return(
                                            <td {...cell.getCellProps()}>
                                                {cell.render('Cell')}
                                            </td>
                                        );
                                    })
                                }
                                
                            </tr>
                        );
                    })
                }
            </tbody>
        </table>
    );

}