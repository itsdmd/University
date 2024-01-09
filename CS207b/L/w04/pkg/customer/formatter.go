package customer

type format int

const (
	PLAINTEXT format = iota
	HTML
)

type IStatementFormatter interface {
	GetStatement(customer Customer) string
}

type StatementFormatter struct {
	result string
}

type StatementFormatterFactory struct{}
