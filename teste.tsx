import React, { Component } from "react"
import { DataTable } from 'primereact/datatable'
import { Column } from 'primereact/column'
import { Calendar } from 'primereact/calendar'
import { Funcionario, Jornada, State } from "./interfaces"
import { Button } from 'primereact/button'
import { Divider } from "primereact/divider"
import { Dropdown } from "primereact/dropdown"
import addToastMessage from "../../../../components/addmessagetoast/addMessageToast"
import { Navigate } from "react-router"
import formateDate from "../../../../utils/FormateDate"
import FULL_ROUTES_ENUM from "../../../../routes/full_routes"
import Service from "./Service";


class CadastroFolhaDePonto extends Component<{}, State> {
    service: Service;
    constructor(props: any) {
        super(props)
        this.service = new Service()
        this.state = {
            inPromise: false,
            date: null,
            datas: [],
            funcionarios: [],
            funcionariosSelected: [],
            funcionarioSelected: null,
            folhaPonto: null,
            jornada: null,
            jornada_id: null,
            comeBackPage: false,
            jornadas: [],
        };
    }

    async componentDidMount(): Promise<void> {

        await this.getUsuarios()
        await this.getJonadas()
        if(this.state.jornada_id){
            await this.getCurrentFolhaPonto()
        }
        
    }


    async getUsuarios() {
        this.setState({ inPromise: true })

        await this.service.getUserMiniempresa(1).then(
            ({ data }) => this.setState({ funcionarios: data, funcionariosSelected: data })
            ,
            () => addToastMessage('error', 'Ocorreu um erro ao buscar os usuários!')
        ).finally(() => this.setState({ inPromise: false }))
    }

    async getJonadas() {
        this.setState({ inPromise: true })
        await this.service.getJornadas(1).then(
            ({ data }:{data:Array<Jornada>}  ) => {
                const datas = data.map((jornada: Jornada ) => jornada.data)
                this.setState({ 
                    datas, 
                    date: formateDate(datas[datas.length - 1]), 
                    jornadas: data,  
                    jornada: data[data.length - 1].num_jornada,
                    jornada_id: data[data.length - 1].id,
                })
            },
            () => addToastMessage('error', 'Ocorreu um erro ao buscar as jornadas!')
        ).finally(() => this.setState({ inPromise: false }))

    }

    async getCurrentFolhaPonto(){
      
        this.setState({ inPromise: true })
        await this.service.getCurrentFolhaPonto(this.state.jornada_id).then(
            ({ data }:{data:Funcionario[]}  ) => {
                this.setState({ 
                    funcionariosSelected: data
                })
            },
            () => addToastMessage('error', 'Ocorreu um erro ao buscar jornada atual!')
        ).finally(() => this.setState({ inPromise: false }))
    }



    handleJornadaChange = ({ value }: { value: number }) => {
        this.getCurrentFolhaPonto()

        const selectedJornada = this.state.jornadas.find((jornada: Jornada) => jornada.num_jornada === value);

        if (selectedJornada){
            this.setState({ date: formateDate(selectedJornada.data), jornada: value, jornada_id: selectedJornada.id })
        }
            
    };

    handleSelectionChange = ({ value }: { value: Funcionario[] }) => {
        this.setState({funcionariosSelected: value})
    };

    async handleSave(e: any): Promise<void> {
        e.preventDefault()
     
        this.setState({ inPromise: true });
        await this.service.registerFolhaponto({
        miniempresa_id: 1,
        jornada_id: this.state.jornada_id,
        users_folhaponto: this.state.funcionariosSelected.length > 0 ? this.state.funcionariosSelected.map((usr) => usr.user_id) : [0],
        }).then(
            ({ data }) => {
                addToastMessage('success', data)
            },
            ({ response }) => addToastMessage('warn', response.data)
        ).finally(() => this.setState({ inPromise: false }))
        } 

    render() {
        const headerDataTable = (
            <div>
                <div className="grid table-header pt-2">
                    <div className="col-2">
                        <span className="p-float-label">
                            <Calendar dateFormat="dd/mm/yy" disabled value={this.state.date} onChange={({ value }) => this.setState({ date: value })} />
                            <label>Data</label>
                        </span>
                    </div>
                    <div className="col-2">
                        <span className="p-float-label">
                            <Dropdown
                                value={this.state.jornada}
                                optionValue="num_jornada"
                                onChange={this.handleJornadaChange}
                                options={this.state.jornadas}
                                optionLabel="num_jornada"
                            />
                            <label>Encontro</label>
                        </span>
                    </div>
                </div>
            </div>
        )

        return (
            <div>
                <h1 className="text-5xl mb-3">Cadastro - Folha de Ponto</h1>
                <h2>Registro de presença - 1º Encontro</h2>
                <div className="grid mt-4">
                    <div className="col-7">
                        <DataTable
                            header={headerDataTable}
                            selection={this.state.funcionariosSelected}
                            onSelectionChange={this.handleSelectionChange}
                            value={this.state.funcionarios}
                        >
                            <Column selectionMode="multiple" headerStyle={{ width: '3em' }}></Column>
                            <Column field="nome" header="Nome" />
                            <Column field="cargo" header="Cargo" />
                        </DataTable>
                        <Divider />
                        <div className="grid justify-content-end">
                            <div className="col-2" style={{ width: '150px' }}>
                                <Button
                                    onClick={() => this.setState({ comeBackPage: true })}
                                    label="Cancelar"
                                    className="p-button-danger w-12 "
                                    icon="pi pi-times"
                                />
                            </div>
                            <div className="col-2" style={{ width: '150px' }}>
                                <form onSubmit={e=>this.handleSave(e)}>
                                <Button
                                    label="Salvar"
                                    className="p-button-success w-12"
                                    icon="pi pi-check"
                                />
                                </form>
                                

                            </div>
                        </div>
                    </div>
                    {this.state.comeBackPage && (<Navigate to={FULL_ROUTES_ENUM.PESSOAL.FOLHA_PONTO} />)}
                </div>


            </div>
        )
    }
}


export default CadastroFolhaDePonto